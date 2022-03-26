# nxprayer changelog

## v2.0.0 -- 2022-03-26

**Added**
- Hijri date with option --hijri.
- All files are now in the `home` directory.
- No need for `sudo` anymore to build the package.
- The `threshold` parameter moved to the executable `events.cpp` file.

**Fixed**
- `Refactor` the codebase.
- Follow the `google coding style`.
- Fetching the data for 1 year instead of 6.
- The default year is the current year.
- Reduce the number of `source line of code`.
- Remove `icons` from the output due to the compatibility issues with terminal.


---


## v1.0.1 -- 2021-11-06

**Added**

- Hybrid mode for tracking the elapsed time until threshold.
- Version

**Fixed**

- Fetching the data using urlopen lib.


---


## v0.1.9 -- 2021-11-03

**Added**

- Time of the previous prayer.
- Elapsed time since the previous prayer.

**Fixed**

- Clean up local_api code
- Increase the period of time for notification to be persistent.
- Add elapsed time for notifications when the status bar got clicked.
- Remove Midnight and Imsak from timings.
