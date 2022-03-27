# next-prayer - Next Islamic prayer
.POSIX:

VERSION = $(shell awk '/VERSION\[\] =/ {print $$5}' np_main.cpp | sed "s/\"\|;//g")

SRC = *.cpp
HDR = *.h

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++20 -pedantic -O3 -DNDEBUG

LOCAL_PREFIX = $(HOME)/.local
CONFIG_PREFIX = $(HOME)/.config

# ANSI colors for shell output
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
NC=\033[0m # No Color

# ANSI colors for shell output (bold)
BBLACK=\033[1;30m
BRED=\033[1;31m
BGREEN=\033[1;32m
BYELLOW=\033[1;33m
BBLUE=\033[1;34m
BPURPLE=\033[1;35m
BCYAN=\033[1;36m
BWHITE=\033[1;37m

np_main: $(SRC)
	@printf "%b" "$(YELLOW)Compiling the source code...$(WHITE)\n"
	sed -i "s|IAMUName|$(HOME)|" np_main.cpp
	$(CC) $(CFLAGS) -o np_main $(SRC)
	sed -i "s|$(HOME)|IAMUName|" np_main.cpp
	@printf "%b" "$(BGREEN)Compilation Done!$(NC)\n\n"

install: np_main
	@printf "%b" "$(PURPLE)Fetching API Data...$(WHITE)\n"
	python3 np_fetch.py
	cp -u np_fetch.py $(LOCAL_PREFIX)/bin/
	cp -u np_main $(LOCAL_PREFIX)/bin/
	cp -u next-prayer $(LOCAL_PREFIX)/bin/
	mkdir -p $(LOCAL_PREFIX)/share/man/man1/
	sed "s/VERSION/$(VERSION)/" next-prayer.1 > $(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	@printf "%b" "$(BCYAN)next-prayer$(BGREEN) Installed Successfully!$(NC)\n"

uninstall:
	@printf "%b" "$(BYELLOW)Uninstalling...$(WHITE)\n"
	rm -rf $(LOCAL_PREFIX)/share/next-prayer
	rm -f $(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	rm -f $(LOCAL_PREFIX)/bin/next-prayer
	rm -f $(LOCAL_PREFIX)/bin/np_main
	rm -f $(LOCAL_PREFIX)/bin/np_fetch.py
	rm -f $(LOCAL_PREFIX)/bin/np_config.py
	@printf "%b" "$(BCYAN)next-prayer$(BGREEN) uninstalled.$(NC)\n\n"

clean:
	@printf "%b" "$(YELLOW)Cleaning...$(WHITE)\n"
	rm -f np_main
	@printf "%b" "$(BGREEN)Cleaning done.$(NC)\n\n"

.PHONY: all clean install uninstall
