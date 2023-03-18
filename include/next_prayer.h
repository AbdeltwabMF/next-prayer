#pragma once

#include <stdint.h>

namespace nxpr
{
  typedef enum PRAYER_NAME
  {
    PRAYER_NAME_FAJR = 1,
    PRAYER_NAME_SHROUQ,
    PRAYER_NAME_DHUHR,
    PRAYER_NAME_ASR,
    PRAYER_NAME_MAGHRIB,
    PRAYER_NAME_ISHA,
    PRAYER_NAME_UNKNOWN
  } PRAYER_NAME;

  typedef struct Time
  {
    uint8_t seconds;
    uint8_t minutes;
    // in 24-h system
    uint8_t hours;

    bool operator<(const Time& others) const
    {
      if (this->hours == others.hours)
      {
        return (this->minutes < others.minutes);
      }

      return (this->hours < others.hours);
    }

    bool operator==(const Time& others) const
    {
      return (this->hours == others.hours) && (this->minutes == others.minutes);
    }
  } Time;

  typedef struct Prayer
  {
    PRAYER_NAME name;
    Time timing;
  } Prayer;

  template <typename F>
  struct Later
  {
    F f;
    Later(F f) : f(f) {}
    ~Later() { f(); }
  };

  static constexpr Time TIME_MIN = {0, 0};
  static constexpr Time TIME_MAX = {24, 60};
  static constexpr uint8_t PRAYERS_NUMBER = 6;

  Prayer prayers[PRAYERS_NUMBER]{};

  Prayer next(Time current_time);
  Prayer previous(Time current_time);

  Prayer* read(const char* file_name);
  void write(const char* file_name);

  char* fetch(const char* url);
}
