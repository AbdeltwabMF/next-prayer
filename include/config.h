#pragma once

// The decimal value for the latitude and longitude co-ordinates of the location you want
// the time computed for. Example: 51.75865125
const char* latitude = "30.05310101838021";
const char* longitude = "31.230989728835304";
// A gregorian calendar year. Example: 2014.
const char* year = "2023";
// A prayer times calculation method. Methods identify various schools of
// thought about how to compute the timings. If not specified,
// it defaults to the closest authority based on the location or
// co-ordinates specified in the API call. This parameter
// accepts values from 0-12 and 99, as specified below:
// 0 - Shia Ithna-Ansari
// 1 - University of Islamic Sciences, Karachi
// 2 - Islamic Society of North America
// 3 - Muslim World League
// 4 - Umm Al-Qura University, Makkah
// 5 - Egyptian General Authority of Survey
// 7 - Institute of Geophysics, University of Tehran
// 8 - Gulf Region
// 9 - Kuwait
// 10 - Qatar
// 11 - Majlis Ugama Islam Singapura, Singapore
// 12 - Union Organization islamic de France
// 13 - Diyanet İşleri Başkanlığı, Turkey
// 14 - Spiritual Administration of Muslims of Russia
// 15 - Moonsighting Committee Worldwide (also requires shafaq paramteer)
// 99 - Custom. See https://aladhan.com/calculation-methods
const char* method = "5";
// Number of days to adjust Hijri date(s). Example: 1 or 2 or -1 or -2
const char* adjustment = "1";