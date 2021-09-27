# Next Prayer (nxprayer)

Show me the time of the next `Islamic prayer`.

---

## Features
	- showing the `next prayer time`.
	- `send notification` if it's the time for a prayer.
	- showing the `remaining time` till the next prayer.

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
FLAGS:
  -r,	--remain	Remaining time till the next prayer
  -n,	--next		The name and the time for the next prayer
  -d,	--adhan		Is it time for adhan or not by returning binary value(0, 1)
  -h,	--help		Showing this info
```

##### Terminal

```
$ nxprayer -n
🕌 Dhuhr 11:47 AM

$ nxprayer -r
05:13
```


##### Status bars:
If you are using [dwmblocks](https://github.com/torrinfail/dwmblocks) or [i3blocks](https://github.com/vivien/i3blocks) you could put `nxprayer` in your `config` file as a script.


##### Screenshot

![np](np.png)

---

## Dependencies

`jq` `python3` `gawk` `gcc` `bash` `libnotify`


##### For Arch based systems, the package in the `AUR` 🥰:

```
yay -S nxprayer
```

##### For other distros:

```
git clone https://github.com/AbdeltwabMF/nxprayer.git
cd nxprayer
make clean install
```

---

## [License](LICENSE)

Licensed under the GPL-v3 License.
