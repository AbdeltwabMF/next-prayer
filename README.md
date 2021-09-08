# Next Prayer

The whole purpose of this script is to tell us what is the time of the next prayer.
however, the script capable to be extended.
in the current version for example it can do:

```
  --rem           Remaining time till the next prayer
  --nxt           The name and the time for the next prayer
  --adn           Is it time for adhan or not by returning binary value(0, 1)
  --help, -h      Showing this info
```

---

## Installation

```
git clone https://github.com/AbdeltwabMF/Next-Prayer.git
cd Next-Prayer
./install
NextPrayer
```
---

## Usage

```
> NextPrayer --nxt
Midnight 11:54 PM

> NextPrayer --adn
1

> NextPrayer --rem
00:39
```

---

## Dependencies
  - `jq`
  - `python3`
  - `gawk`
  - `g++`
  - `bash`

for Arch based systems:
```
sudo pacman -S gcc gawk python3 bash jq
```

---

## [License](LICENSE)
Licensed under the GPLv3 License.
