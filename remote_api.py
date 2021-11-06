#!/bin/python3

import json
import os
import requests

config_file = "/home/amf/.config/next-prayer/config.json"
data_path = "/usr/local/share/next-prayer/calendar"
root_url = "http://api.aladhan.com/v1/calendar?"

if os.path.exists(config_file):
    pass
else:
    print("Error: ~/.config/next-prayer/config.json not found!.")
    exit(1)

with open(config_file) as f:
    pms = json.load(f)

years = int(pms["year"])
url = root_url + "latitude=" + pms["latitude"] + "&longitude=" + pms["longitude"] + "&method=" + pms["method"] + "&annual=" + pms["annual"] + "&adjustment=" + pms["adjustment"]

for i in range(6):
    calender = requests.get(url + "&year=" + str(years + i)).json()

    if calender["status"] == "OK":
        pass
    else:
        print("Oops.. something went wrong!", "Check internet connction", sep="\n")
        exit(1)

    year = []
    for month in range(12):
        year.append(calender["data"]["{}".format(month + 1)])

    for month in year:
        for day in month:
            del day["meta"]
            del day["timings"]["Sunset"]
            del day["timings"]["Imsak"]
            del day["timings"]["Midnight"]
            del day["date"]["readable"]
            del day["date"]["timestamp"]
            del day["date"]["gregorian"]
            del day["date"]["hijri"]["format"]
            del day["date"]["hijri"]["day"]
            del day["date"]["hijri"]["weekday"]
            del day["date"]["hijri"]["year"]
            del day["date"]["hijri"]["designation"]
            del day["date"]["hijri"]["holidays"]

    for month in range(len(year)):
        for day in range(len(year[month])):
            with open(data_path + "/{}/".format(years + i) + "{}/".format(month + 1) + "{}".format(day + 1), "w") as f:
                f.write(json.dumps(year[month][day]))
