#!/bin/python3
"""
 - Check for Bin, Config and Data dirs and files
 - Fetch the data from the API for 1 year
 - And save it locally.
"""
import os
import sys

import requests
from config import get_api_params

HOME = os.path.expanduser("~")
LOCAL_PREFIX = HOME + "/.local/"
CONFIG_PREFIX = HOME + "/.config/"

CONF_DIR = os.path.join(CONFIG_PREFIX, "next-prayer/")
DATA_DIR = os.path.join(LOCAL_PREFIX, "share/next-prayer/")
MAN_DIR  = os.path.join(LOCAL_PREFIX, "share/man/man1/")
BIN_DIR  = os.path.join(LOCAL_PREFIX, "bin/")

ROOT_URL = "http://api.aladhan.com/v1/calendar?"

def check_dirs():
    """
    Check if the directories exist, and create them if they don't.
    """
    if not os.path.exists(CONF_DIR):
        os.makedirs(CONF_DIR, exist_ok=True)
        os.chmod(CONF_DIR, 0o754)
    if not os.path.exists(DATA_DIR):
        os.makedirs(DATA_DIR, exist_ok=True)
        os.chmod(DATA_DIR, 0o754)
    if not os.path.exists(MAN_DIR):
        os.makedirs(MAN_DIR, exist_ok=True)
        os.chmod(DATA_DIR, 0o755)
    if not os.path.exists(BIN_DIR):
        os.makedirs(BIN_DIR, exist_ok=True)

def check_files():
    """
    Check if the config file exist, and raise an error if it doesn't.
    """
    if os.path.exists(CONF_DIR + "config.py"):
        pass

    elif os.path.exists(BIN_DIR + "config.py"):
        os.symlink(BIN_DIR + "config.py", CONF_DIR + "config.py")

    elif os.path.exists("config.py"):
        os.system(f"cp -u config.py {BIN_DIR}")
        os.symlink(BIN_DIR + "config.py", CONF_DIR + "config.py")

    else:
        # TODO: make this a proper error
        print("No config file found. Please run `next-prayer init`")
        sys.exit(1)

    os.system(f"cp -u next-prayer.1 {MAN_DIR}")
    os.system(f"cp -u next-prayer {BIN_DIR}")
    os.system(f"cp -u events {BIN_DIR}")
    os.system(f"cp -u fetch.py {BIN_DIR}")


def get_url():
    """
    Get the URL to fetch the data from.
    """
    params = get_api_params()
    return ROOT_URL + "&".join([f"{k}={v}" for k, v in params.items()])


def write_data(data):
    """
    Write the data to a file.
    """
    year = []
    for month in range(12):
        year.append(data["data"][f"{month + 1}"])

    for _month in year:
        for _day in _month:
            # The day ID
            date = _day['date']['gregorian']['date']

            # Write the data to a file
            with open(DATA_DIR + date + ".txt", "w", encoding="utf-8") as file:
                file.write(f"Fajr {_day['timings']['Fajr'][0:5]}\n")
                file.write(f"Sunrise {_day['timings']['Sunrise'][0:5]}\n")
                file.write(f"Dhuhr {_day['timings']['Dhuhr'][0:5]}\n")
                file.write(f"Asr {_day['timings']['Asr'][0:5]}\n")
                file.write(f"Maghrib {_day['timings']['Maghrib'][0:5]}\n")
                file.write(f"Isha {_day['timings']['Isha'][0:5]}\n")
                file.write(f"{_day['date']['hijri']['day']}\n")
                file.write(f"{_day['date']['hijri']['month']['ar']}\n")
                file.write(f"{_day['date']['hijri']['month']['en']}\n")
                file.write(f"{_day['date']['hijri']['year']}\n")

def fetch_data():
    """
    Fetch the data from the API and save it locally.
    """
    response = requests.get(get_url())
    if response.status_code == 200:
        write_data(response.json())
    else:
        print("Error fetching data from API")
        sys.exit(1)

def __main__():
    check_dirs()
    check_files()
    fetch_data()

__main__()
