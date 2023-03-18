#include <next_prayer.h>
#include <constants.h>
#include <config.h>

#include <assert.h>
#include <stdio.h>

#include <fmt/core.h>
#define HTTP_IMPLEMENTATION
#include <http.h>
#include <cJSON.h>

namespace nxpr
{
  Prayer next(Time current_time)
  {
    auto res = Prayer{PRAYER_NAME_UNKNOWN, TIME_MAX};
    for (auto& [name, timing] : prayers)
    {
      if (current_time < timing)
      {
        if (timing < res.timing)
        {
          res.name = name;
          res.timing = timing;
        }
      }
    }

    if (res.name == PRAYER_NAME_UNKNOWN)
    {
      res = prayers[0];
    }

    return res;
  }

  Prayer previous(Time current_time)
  {
    auto res = Prayer{PRAYER_NAME_UNKNOWN, TIME_MIN};
    for (auto& [name, timing] : prayers)
    {
      if (timing < current_time)
      {
        if (res.timing < timing)
        {
          res.name = name;
          res.timing = timing;
        }
      }
    }

    if (res.name == PRAYER_NAME_UNKNOWN)
    {
      res = prayers[PRAYERS_NUMBER - 1];
    }

    return res;
  }

  Prayer* read(const char* file_name)
  {
    FILE* handle = fopen(file_name, "r");
    assert(handle != nullptr);
    Later L1 = Later([&]() { ::fclose(handle); });

    Prayer* res = nullptr;

    return res;
  }

  void write(const char* file_name)
  {
    FILE* handle = fopen(file_name, "w");
    assert(handle != nullptr);
    Later L1 = Later([&]() { fclose(handle); });

    std::string url_params = fmt::format("{}?{}={}&{}={}&{}={}&{}={}",
    year,
    "latitude", latitude,
    "longitude", longitude,
    "method", method,
    "adjustment", adjustment);

    fmt::print(fmt::format("{}{}", base_url, url_params).c_str());
    auto response = fetch(fmt::format("{}{}", base_url, url_params).c_str());
    printf("%s",response);

    auto json = cJSON_Parse(response);
    Later L2 = Later([&]() { cJSON_free(json); });
  }

  char* fetch(const char* url)
  {
    http_t* request = http_get(url, nullptr);
    Later L1 = Later([&]() { http_release(request); });
    if (request == nullptr)
    {
      fmt::print("Invalid request.\n");
      return nullptr;
    }

    http_status_t status = HTTP_STATUS_PENDING;
    while (status == HTTP_STATUS_PENDING)
    {
      status = http_process(request);
    }

    if (status == HTTP_STATUS_FAILED)
    {
      fmt::print("HTTP request failed ({}): {}.\n", request->status_code,
        request->reason_phrase);
      return nullptr;
    }

    auto response = (char*)malloc(request->response_size + 1);
    ::memcpy_s(response, request->response_size, request->response_data, request->response_size);
    response[request->response_size] = '\0';

    return response;
  }
} // namespace nxpr

int main(int argc, char const* argv[])
{
  nxpr::write("file.txt");
  return 0;
}
