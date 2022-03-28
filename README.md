<h1 align="center">Next Prayer</h1>
<h4 align="center"> <em>Islamic prayers reminder for your status bar.</em> </h4>

[![GitHub Super-Linter](https://github.com/abdeltwabmf/continuous-id/workflows/Lint%20Code%20Base/badge.svg)](https://github.com/marketplace/actions/super-linter)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/AbdeltwabMF/next-prayer/graphs/commit-activity)
![Maintainer](https://img.shields.io/badge/maintainer-Abdeltwabmf-blue)
[![Linux](https://svgshare.com/i/Zhy.svg)](https://svgshare.com/i/Zhy.svg)
[![Docker](https://badgen.net/badge/icon/docker?icon=docker&label)](https://https://docker.com/)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
[![GitHub release](https://img.shields.io/github/release/Naereen/StrapDown.js.svg)](https://github.com/AbdeltwabMF/next-prayer/releases/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)

# Demo
![live demo](./assets/usage.GIF)

# Usage

```bash
Usage: next_prayer [options...]

Options:
 --next      The next prayer and its time.
 --prev      The previous prayer and its time.
 --hybrid    The elapsed time since the previous prayer as far as the elapsed time <= THRESHOLD.
 --all       Show all timings.
 --left      The time left till the next prayer.
 --elapsed   The time elapsed since the previous prayer.
 --adhan     Whether the current time is adhan or not.
 --hijri     The current hijri date.
 --help      Display this help message.
 --version   Display the version.
```

# Installation

For `Arch, btw based distros` run the following command:
```bash
yay -S next-prayer
```

For `Ubuntu, RedHat or any other distro` run the following:
```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
make clean install
```

For `windows users or Docker` version

- Pull the image from [Docker Hub](https://hub.docker.com/repository/docker/abdeltwabmf/next-prayer), and run the following command:
```bash
docker pull abdeltwabmf/next-prayer:latest
```

Verify the install
```bash
docker container run --rm  abdeltwabmf/next-prayer np_main --version
```
`Version: v2.0.0`

- Or build it yourself
```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
docker build -t next-prayer .
```

Verify the build
```bash
docker container run --rm next-prayer np_main --version
```
`Version: v2.0.0`

**How to use next-prayer with Docker**

The use is pretty much the same.
```bash
docker container run --rm  abdeltwabmf/next-prayer np_main [options...]
```

# Setup for status bars

- [dwmblocks](https://github.com/torrinfail/dwmblocks)

_In config.h add this 4-element Block to the blocks[] array_
``` c
static const Block blocks[] = {
  /*Icon*/  /*Command*/              /*Update Interval*/  /*Update Signal*/
  {"🕌 ",    "next-prayer --hybrid",  29,                  0}
}
```

- [i3blocks](https://github.com/vivien/i3blocks)

_In i3blocks config add this section_
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

# [License](LICENSE)

Licensed under the [GPL-v3 License](LICENSE).
