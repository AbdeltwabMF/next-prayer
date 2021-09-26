# Next Prayer (nxprayer)

The main purpose of this script is to tell us what is the time of the next prayer.
However, the script capable to be extended.
In the current version for example it can do:

```
FLAGS:
  -r,	--remain	Remaining time till the next prayer
  -n,	--next		The name and the time for the next prayer
  -d,	--adhan		Is it time for adhan or not by returning binary value(0, 1)
  -h,	--help		Showing this info
```

---

## Installation

```
git clone https://github.com/AbdeltwabMF/nxprayer.git
cd nxprayer
make clean install
```
---

## Usage

```
$ nxprayer -next
Midnight 11:54 PM

$ nxprayer -adhan
0

$ nxprayer -remain
00:39
```

---

## Screenshot
![np](np.png)

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
