<h1 align="center" color="Magenta">Next Prayer</h1>

<h4 align="center"> <em>Islamic prayers reminder for your status bar.</em> </h4>

[![Linux](https://img.shields.io/badge/Platform-Linux-2e8b57?logo=linux&.svg)](https://github.com/AbdeltwabMF/next-prayer#installation=)
[![Docker](https://badgen.net/badge/icon/docker?icon=docker&label)](https://https://docker.com/)
[![COPYING](https://img.shields.io/github/license/AbdeltwabMF/next-prayer?logo=gnu&.svg)](https://github.com/AbdeltwabMF/next-prayer/blob/main/LICENSE)
[![contributors](https://img.shields.io/github/contributors/AbdeltwabMF/next-prayer.svg)](https://github.com/AbdeltwabMF/next-prayer/graphs/contributors)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
[![GitHub release](https://img.shields.io/github/release/AbdeltwabMF/next-prayer.svg)](https://github.com/AbdeltwabMF/next-prayer/releases/)
[![GitHub Super-Linter](https://github.com/abdeltwabmf/continuous-id/workflows/Lint%20Code%20Base/badge.svg)](https://github.com/marketplace/actions/super-linter)


# Usage

```bash
Usage: next-prayer [options...]

Options:
  --help       Show this help message and exit.
  --version    Show version information and exit.
  --next       Show next prayer time.
  --all        Show all timings.
  --prev       Show previous prayer time.
  --left       Show time left to next prayer.
  --elapsed    Show elapsed time since last prayer.
  --adhan      Show if adhan is now playing.
  --hijri      Show hijri date.
  --hybrid     The elapsed time since the previous prayer as far as the elapsed time <= THRESHOLD.
```

---

# Installation

- For `Arch based distros (e.g. Manjaro)` install it using any `AUR` helper.

```bash
yay -S next-prayer
```

- For `Other distros (e.g Ubuntu, ...)` run the following commands:

```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
make all clean install
```

- For `Windows or Mac` you probably end up with `Docker version`: <br>

&nbsp; &nbsp; You have two choices:

1. Use [***Docker Hub***](https://hub.docker.com/r/abdeltwabmf/next-prayer) image by running the following command:

```bash
docker pull abdeltwabmf/next-prayer
docker tag abdeltwabmf/next-prayer next-prayer

docker run --rm next-prayer next-prayer --version
```

2. Build it yourself by running the following commands:

```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer

docker build -t next-prayer .
docker run --rm next-prayer next-prayer --version
```

:heavy_check_mark: You shall see `Version: v2.0.0` indicating that you run the container successfully. <br>

<h4 align="center"><em>Using next-prayer options with docker</em></h4>

<pre align="center"><code>docker run --rm next-prayer next-prayer [options...]</code></pre>

---

# Configuration

:warning: ***Only if you're using DockerHub image***

1. After Editing your config file save it locally and run the following command to fetch API data:

```dockerfile
docker run --rm -v /path/to/your/config:/root/.config/next-prayer/np_config.py -v /path/to/your/data:/root/.local/share/next-prayer next-prayer np_fetch.py
```

2. After that you can run:

```dockerfile
docker run --rm -v /path/to/your/data:/root/.local/share/next-prayer next-prayer next-prayer [options...]
```

---

# Setup for status bars

- [***dwmblocks***](https://github.com/torrinfail/dwmblocks)


:star2: Add this 4-element Block to the blocks[] array in your config.h.

``` c
static const Block blocks[] = {
  /*Icon*/  /*Command*/              /*Update Interval*/  /*Update Signal*/
  {"🕌 ",    "next-prayer --hybrid",  29,                  0}
}
```


- [***i3blocks***](https://github.com/vivien/i3blocks)


:star2: Add this section to your i3blocks config file.<br>

```code
[next-prayer]
command=next-prayer --hybrid
interval=29
label=<span>🕌 </span>
color=#FF8105
border=#FF8105
border_top=1
border_right=0
border_bottom=0
border_left=0
```

:eyes: If you're using `the docker version` Add `docker run --rm next-prayer`
at the very beginning of the command.<br>

---

# [License](LICENSE)

Licensed under the [GPL-v3 License](LICENSE).
