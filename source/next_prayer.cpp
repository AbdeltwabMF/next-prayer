#include <next_prayer.h>

#include <stdio.h>

#include <fmt/core.h>

namespace np_prayer
{
  Prayer next(Time current_time)
  {
    auto res = Prayer{PRAYER_NAME_UNKNOWN, np_time::TIME_MAX};
    for (auto &[name, timing]: prayers)
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
    auto res = Prayer{PRAYER_NAME_UNKNOWN, np_time::TIME_MIN};
    for (auto &[name, timing]: prayers)
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
} // namespace np_prayer

namespace np_file
{
  void read(const char* path)
  {
    FILE* handle = fopen(path, "rw");
    Later([&](){ fclose(handle); });
    FMT_ASSERT(handle != nullptr, "[FILE ERROR] Can not open file");


  }
} // namespace np_file

