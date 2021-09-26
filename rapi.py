#!/bin/python3

import json
import os
from urllib.request import urlopen

home = os.path.expanduser("~")
params_path = home
data_path = home

params_path += "/.config/nxprayer/params.json"
data_path += "/.local/share/nxprayer/calendar"
root_url = "http://api.aladhan.com/v1/calendar?"

if os.path.exists(params_path):
    pass
else:
    print("Error: run the 'Makefile'.")
    exit(0)

with open(params_path) as f:
    pms = json.load(f)

with urlopen(root_url + "latitude=" + pms["latitude"] + "&longitude=" + pms["longitude"] + "&method=" + pms["method"] + "&annual=" + pms["annual"] + "&year=" + pms["year"] + "&adjustment=" + pms["adjustment"]) as response:
    calender = json.load(response)

if calender["status"] == "OK":
    pass
else:
    print("Oops.. something went wrong!")
    exit(0)

year = []
for month in range(12):
    year.append(calender["data"]["{}".format(month + 1)])

for month in year:
    for day in month:
        del day["meta"]
        del day["timings"]["Sunset"]
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
        with open(data_path + "/" + "{}".format(month + 1) + "/" + "{}".format(day + 1), "w") as f:
            f.write(json.dumps(year[month][day]))
