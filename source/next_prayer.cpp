#include <next_prayer.h>

#include <assert.h>
#include <stdio.h>

#include <fmt/core.h>
#define HTTP_IMPLEMENTATION
#include <http.h>

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
    Later([&]() { fclose(handle); });
    assert(handle != nullptr);

    Prayer* res;

    return res;
  }

  void write(const char* file_name)
  {
    FILE* handle = fopen(file_name, "w");
    Later([&]() { fclose(handle); });
    assert(handle != nullptr);
  }

  char* get(const char* url)
  {
    http_t* request = http_get(url, nullptr);
    Later([&]() { http_release(request); });
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

    return (char*)request->response_data;
  }
} // namespace nxpr

int main(int argc, char const* argv[]) { return 0; }
