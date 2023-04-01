#!/usr/bin/python3
"""
Customize below to fit your needs.
"""
from datetime import date


def get_api_params():
    """
    Returns a dictionary of api parameters.
    """
    api_params = {
        # (decimal)
        # The decimal value for the latitude co-ordinate of the location you want
        # the time computed for. Example: 51.75865125
        "latitude": "30.05310101838021",
        # (decimal)
        # The decimal value for the longitude co-ordinate of the location you want
        # the time computed for. Example: -1.25387785
        "longitude": "31.230989728835304",
        # (number)
        # A gregorian calendar year. Example: 2014.
        "year": f"{date.today().year}",
        # (boolean)
        # If true, we'll ignore the month and return the calendar for the whole year.
        "annual": "true",
        # (number)
        # A prayer times calculation method. Methods identify various schools of
        # thought about how to compute the timings. If not specified,
        # it defaults to the closest authority based on the location or
        # co-ordinates specified in the API call. This parameter
        # accepts values from 0-12 and 99, as specified below:
        # 0 - Shia Ithna-Ansari
        # 1 - University of Islamic Sciences, Karachi
        # 2 - Islamic Society of North America
        # 3 - Muslim World League
        # 4 - Umm Al-Qura University, Makkah
        # 5 - Egyptian General Authority of Survey
        # 7 - Institute of Geophysics, University of Tehran
        # 8 - Gulf Region
        # 9 - Kuwait
        # 10 - Qatar
        # 11 - Majlis Ugama Islam Singapura, Singapore
        # 12 - Union Organization islamic de France
        # 13 - Diyanet İşleri Başkanlığı, Turkey
        # 14 - Spiritual Administration of Muslims of Russia
        # 15 - Moonsighting Committee Worldwide (also requires shafaq paramteer)
        # 99 - Custom. See https://aladhan.com/calculation-methods
        "method": "5",
        # (number)
        # Number of days to adjust hijri date(s). Example: 1 or 2 or -1 or -2
        "adjustment": "1",
    }
    return api_params
