#!/usr/bin/python3
"""
 - Check for Bin, Config and Data dirs and np_config.py file
    - Ensure that the config file exists
 - Fetch the data from the API for 1 year
    - And save it locally to .local/share/next-prayer/
"""
import os
import sys

from np_config import get_api_params
from requests import ConnectTimeout, HTTPError, ReadTimeout, URLRequired, get

HOME = os.path.expanduser("~")
LOCAL_PREFIX = HOME + "/.local/"
CONFIG_PREFIX = HOME + "/.config/"

CONF_DIR = os.path.join(CONFIG_PREFIX, "next-prayer/")
DATA_DIR = os.path.join(LOCAL_PREFIX, "share/next-prayer/")
BIN_DIR = os.path.join(LOCAL_PREFIX, "bin/")

ROOT_URL = "http://api.aladhan.com/v1/calendar?"

# ANSI colors for terminal output
BLACK = "\033[30m"
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NC = "\033[0m"


def check_dirs():
    """
    Check if the directories exist, and create them if they don't.
    """
    try:
        print(f"{BLUE}Checking directories{NC}")
        if not os.path.exists(CONF_DIR):
            os.makedirs(CONF_DIR, exist_ok=True)
        if not os.path.exists(DATA_DIR):
            os.makedirs(DATA_DIR, exist_ok=True)
        if not os.path.exists(BIN_DIR):
            os.makedirs(BIN_DIR, exist_ok=True)
        print(f"{GREEN}Directories checked{NC}")
    except (OSError) as ex:
        print(f"{RED}Could not check directories{NC}")
        print(f"{YELLOW}Please check you have permissions!{NC}")
        print(ex)
        sys.exit(1)


def check_files():
    """
    Check if the np_config.py file exist, and raise an error if it doesn't.
    """
    try:
        cfg = "np_config.py"
        print(f"{BLUE}Checking config file{WHITE}")
        if os.path.exists(CONF_DIR + cfg):
            if not os.path.exists(BIN_DIR + cfg):
                os.symlink(CONF_DIR + cfg, BIN_DIR + cfg)
        else:
            os.system(f"cp -f src/{cfg} {CONF_DIR}")
            os.symlink(CONF_DIR + cfg, BIN_DIR + cfg)
        print(f"{GREEN}Config file checked{NC}")
    except (OSError) as ex:
        print(f"{RED}Could not check config file{NC}")
        print(f"{YELLOW}Please check you have permissions!{NC}")
        print(f"{WHITE}{ex}{NC}")
        sys.exit(1)


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
            date = _day["date"]["gregorian"]["date"]

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
    try:
        print(f"{BLUE}Fetching data{NC}")
        response = get(get_url())
        if response.status_code == 200:
            write_data(response.json())
            print(f"{GREEN}Data fetched{NC}")
        else:
            print(f"{RED}Could not fetch data{NC}")
            sys.exit(1)
    except (ConnectionError, HTTPError, URLRequired, ConnectTimeout, ReadTimeout) as ex:
        print(f"{RED}Could not fetch data{NC}")
        print(ex)
        sys.exit(1)


if __name__ == "__main__":
    check_dirs()
    check_files()
    fetch_data()
