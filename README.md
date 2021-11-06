# next-prayer

Islamic prayers reminder for status bars.

---

## Usage & Flags

```
-n, --next     		The next prayer and its time.
-p, --previous 		The previous prayer and its time.
-i, --hybrid  		Display the elapsed time since the previous prayer until the elapsed time reach threshold time determined in config file, Then it will display the next prayer and its time.
-e, --elapsed  		The elapsed time since the previous prayer.
-l, --left    		The time left until the next prayer.
-a, --adhan   		Display if it's the time for adhan by returning "yes" or "no".
-h, --help    		Display this help information.
-v, --version  		The current version.
```

---

## Setup for status bars:

### [dwmblocks](https://github.com/torrinfail/dwmblocks):

**In config.h add this 4-element Block to the blocks[] array**

``` c
static const Block blocks[] = {
  /*Icon*/    /*Command*/       /*Update Interval*/  /*Update Signal*/
  {"🕌",      "next-prayer -i",  29,                  0}
}
```

### [i3blocks](https://github.com/vivien/i3blocks):

**In i3blocks config add this section**

```code
[next-prayer]
command=next-prayer -i
interval=29
label=<span>🕌 </span>
color=#FF8105
border=#FF8105
border_top=1
border_right=0
border_bottom=0
border_left=0
```

---

## Snapshot

![np](next-prayer.png)

---

## Installation

### For Arch based systems:

```
yay -S next-prayer
```

### For other distros:

**Install the dependencies first.**

`jq` `python3` `libnotify`

And then do:

``` code
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
sudo make clean install
```

---

## [License](LICENSE)

Licensed under the GPL-v3 License.
