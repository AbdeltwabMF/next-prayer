<h1 align="center" color="Magenta">Next Prayer</h1>

<h4 align="center"> <em>Islamic prayers reminder for Linux status bar</em> </h4>

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

---

## Installation

### 1. Arch-based distributions

```bash
yay -S next-prayer
```

### 2. Build from source

```bash
git clone https://github.com/abdeltwabmf/next-prayer.git
cd next-prayer
make all install
```

### 3. Docker image

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

#### Configuration

1. After updating your configuration file save it locally and run the following command to fetch API data:

```dockerfile
docker run --rm -v /path/to/your/config:/home/nextprayer/.config/next-prayer/np_config.py -v /path/to/your/data:/home/nextprayer/.local/share/next-prayer next-prayer np_fetch.py
```

2. Afterword run the following command:

```dockerfile
docker run --rm -v /path/to/your/data:/home/nextprayer/.local/share/next-prayer next-prayer next-prayer [options...]
```

---

## :thinking: Usage

```shell
Usage: next-prayer [options...]

Options:
  --help       Display this help message.
  --version    Version name.
  --next       Next prayer time.
  --all        All timings.
  --prev       Previous prayer time.
  --left       Time left to next prayer.
  --elapsed    Elapsed time since last prayer.
  --adhan      True if adhan is playing now.
  --hijri      Hijri date.
  --hybrid     The elapsed time since the previous prayer as far as the elapsed time <= THRESHOLD.
```

Use `next-prayer` options with _docker_ as follows:

<pre><code>docker run --rm next-prayer next-prayer [options...]</code></pre>

---

## Setup (Status bar)

Here are some examples how to setup the status bar with next-prayer:

[**_1. dwmblocks_**](https://github.com/torrinfail/dwmblocks)

:star2: Add this 4-element Block to the blocks[] array in your config.h.

```c
static const Block blocks[] = {
  /*Icon*/  /*Command*/              /*Update Interval*/  /*Update Signal*/
  {"🕌 ",    "next-prayer --hybrid",  29,                  0}
}
```

[**_2. i3blocks_**](https://github.com/vivien/i3blocks)

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

---

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

---

## :warning: License

Licensed under the [GPL-v3 License](LICENSE).
