# Next Prayer

The main purpose of this script is to tell us what is the time of the next prayer.
however, the script capable to be extended.
in the current version for example it can do:

```
  --rem, -r	Remaining time till the next prayer
  --nxt, -n	The name and the time for the next prayer
  --adn, -d	Is it time for adhan or not by returning binary value(0, 1)
  --help, -h	Showing this info
```

---

## Installation

```
git clone https://github.com/AbdeltwabMF/Next-Prayer.git
cd Next-Prayer
./install
```
---

## Usage

```
$ NextPrayer --n
Midnight 11:54 PM

$ NextPrayer --d
0

$ NextPrayer --r
00:39
```

---

## Dependencies
 `jq` `python3` `gawk` `g++` `bash` `libnotify`


> for Arch based systems:
```
sudo pacman -S gcc gawk python3 bash jq libnotify
```

---

## [License](LICENSE)
Licensed under the GPL-v3 License.
