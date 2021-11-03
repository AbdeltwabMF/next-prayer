# Next Prayer (nxprayer)

`Islamic prayers` reminder, for Linux status bars.

---

## Features
- displays the `next prayer time`.
- `send notification` if it's the time for a prayer.
- displays the `time left` until the next prayer.
- displays the `elapsed time` since the previous prayer.

---

## Usage

```
FLAGS:

	-l, --left 		display the time left until the next prayer.
	-e, --elapsed	display the elapsed time since the previous prayer.
	-n, --next 		display the time of the next islamic prayer.
	-p, --prev 		display the time of the previous islamic prayer.
	-a, --adhan 	display if it's the time for adhan by returning "yes" or "no".
	-h, --help		display this help information.
```

##### Terminal

```
$ nxprayer -n
🕌 Dhuhr 11:47 AM

$ nxprayer -p
🕌 Sunrise 06:11 AM

$ nxprayer -l
05:17

$ nxprayer -e
00:19

$ nxprayer -a
no
```


##### Status bars:
If you are using [dwmblocks](https://github.com/torrinfail/dwmblocks) or [i3blocks](https://github.com/vivien/i3blocks) you could put `nxprayer` in your `config` file as a script.


##### Screenshot

![np](nxprayer.png)

---

## Installation

##### For Arch based systems:

```
yay -S nxprayer
```

##### For other distros:

##### Dependencies
`Install the dependencies first.`

`jq` `python3` `gawk` `gcc` `bash` `libnotify`

And then.

```
git clone https://github.com/AbdeltwabMF/nxprayer.git
cd nxprayer
sudo make clean install
```

---

## [License](LICENSE)

Licensed under the GPL-v3 License.
