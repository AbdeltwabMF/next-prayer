<div align="center"><img src="assets/next-prayer.png" width=300 alt="next prayer logo" /></div>
<h1 align="center" color="Magenta">Next Prayer</h1>

<h4 align="center"> <em>Islamic prayers reminder for your *nix status bar.</em> </h4>

<div align="center">
    <a href="https://github.com/AbdeltwabMF/next-prayer/graphs/commit-activity">
        <img src="https://img.shields.io/badge/Maintained%3F-yes-green.svg" alt="maintenance" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer/blob/main/LICENSE">
        <img src="https://img.shields.io/github/license/AbdeltwabMF/next-prayer?logo=gnu&.svg" alt="license" />
    <a>
    <a href="https://github.com/AbdeltwabMF/next-prayer/releases">
        <img src="https://img.shields.io/github/release/AbdeltwabMF/next-prayer.svg" alt="release" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer/graphs/contributors">
        <img src="https://img.shields.io/github/contributors/AbdeltwabMF/next-prayer.svg" alt="contributors" />
    </a>
    <a href="http://makeapullrequest.com">
        <img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square" alt="pull-request" />
    </a>
    <a href="https://hub.docker.com/r/abdeltwabmf/next-prayer">
        <img src="https://img.shields.io/docker/image-size/abdeltwabmf/next-prayer/latest" alt="docker" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer">
        <img src="https://img.shields.io/github/languages/top/AbdeltwabMF/next-prayer" alt="languages" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer/CODE-OF-CONDUCT.md">
        <img src="https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg" alt="code-of-conduct" />
    </a>
    <a href="https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=AbdeltwabMF/next-prayer&amp;utm_campaign=Badge_Grade">
        <img src="https://app.codacy.com/project/badge/Grade/7abde45beb1a44ef858fb68e889a214e" alt="quality" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer/graphs/commit-activity">
        <img src="https://img.shields.io/github/commit-activity/w/abdeltwabmf/next-prayer" alt="commits" />
    </a>
    <a href="https://github.com/AbdeltwabMF/next-prayer">
        <img src="https://img.shields.io/tokei/lines/github/AbdeltwabMF/next-prayer" alt="lines-of-code" />
    </a>
</div>

<br />

_If you have any improvements, do not hesitate to post an [issue](https://github.com/AbdeltwabMF/next-prayer/issues/new/) or make a [pull request](https://github.com/AbdeltwabMF/next-prayer/pulls). Your support is very much appreciated! [star on GitHub](https://github.com/AbdeltwabMF/next-prayer/stargazers)_

## Installation

For Arch based distros (e.g. Manjaro) you could install `next-prayer` using `yay`.

```bash
yay -S next-prayer
```

As for Other distros (e.g Ubuntu, ...) run the following commands:

```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
make all install clean
```

As for Windows or Mac you probably end up using the `Docker` version <br />

&nbsp; &nbsp; You have two choices:

1. Use [**_Docker Hub_**](https://hub.docker.com/r/abdeltwabmf/next-prayer) image by running the following commands:

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

:heavy_check_mark: You shall see `Version: vx.x.x` indicating that you run the container successfully. <br>

## :thinking: Usage

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

Use `next-prayer` options with _docker_ as follows:

<pre><code>docker run --rm next-prayer next-prayer [options...]</code></pre>

## Configuration

:warning: **_Only if you're using DockerHub image_**

1. After updating your configuration file save it locally and run the following command to fetch API data:

```dockerfile
docker run --rm -v /path/to/your/config:/home/nextprayer/.config/next-prayer/np_config.py -v /path/to/your/data:/home/nextprayer/.local/share/next-prayer next-prayer np_fetch.py
```

2. Afterword run the following command:

```dockerfile
docker run --rm -v /path/to/your/data:/home/nextprayer/.local/share/next-prayer next-prayer next-prayer [options...]
```

### Setup for status bars

Here are some examples of how to setup the status bar for your distro.

[**_dwmblocks_**](https://github.com/torrinfail/dwmblocks)

:star2: Add this 4-element Block to the blocks[] array in your config.h.

```c
static const Block blocks[] = {
  /*Icon*/  /*Command*/              /*Update Interval*/  /*Update Signal*/
  {"🕌 ",    "next-prayer --hybrid",  29,                  0}
}
```

[**_i3blocks_**](https://github.com/vivien/i3blocks)

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

:eyes: If you're using the docker version Add `docker run --rm next-prayer` at the very beginning of your command.

## :hatching_chick: Contributors

<table>
  <tr>
    <td align="center">
        <a href="https://abdeltwabmf.github.io">
        <img src="https://avatars.githubusercontent.com/u/55063723?v=4?s=100" width="100px;" alt="Abdeltwabmf"/><br />
            <sub><b>Abd El-Twab M. Fakhry</b></sub>
        </a>
    </td>
    <td align="center">
        <a href="https://mazzensaadd.github.io">
        <img src="https://avatars.githubusercontent.com/u/69648110?v=4?s=100" width="100px;" alt="mazzensaadd"/><br />
            <sub><b>Mazen Saad</b></sub>
        </a>
    </td>
    <td align="center">
        <a href="https://github.com/MustafaAmer-1">
        <img src="https://avatars.githubusercontent.com/u/53836898?v=4?s=100" width="100px;" alt="MustafaAmer-1"/><br />
            <sub><b>Mustafa Amer</b></sub>
        </a>
    </td>
  </tr>
</table>

## :warning: License

Licensed under the [GPL-v3 License](LICENSE).
