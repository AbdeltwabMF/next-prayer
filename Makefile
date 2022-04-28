# next-prayer - Next Islamic prayer
.POSIX:

VERSION := $(shell awk '/VERSION\[\] =/ {print $$5}' src/np_main.cpp | sed "s/\"\|;//g")
SHELL := /bin/bash

SRC := src/*.cpp
OBJ := *.o
BIN := np_main

CC := g++
CFLAGS := -std=c++2a -pedantic -O3

LOCAL_PREFIX := $(HOME)/.local
CONFIG_PREFIX := $(HOME)/.config

# ANSI colors for shell output
BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
PURPLE := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
NC := \033[0m # No Color

# ANSI colors for shell output (bold)
BBLACK := \033[1;30m
BRED := \033[1;31m
BGREEN := \033[1;32m
BYELLOW := \033[1;33m
BBLUE := \033[1;34m
BPURPLE := \033[1;35m
BCYAN := \033[1;36m
BWHITE := \033[1;37m

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)
	@printf "%b" "$(GREEN)Compilation Done!$(NC)\n\n"

$(OBJ): $(SRC)
	@printf "%b" "$(BYELLOW)Compiling the source code...$(WHITE)\n"
	sed -i "s|IAMUName|$(HOME)|" src/np_main.cpp
	$(CC) $(CFLAGS) -c $(SRC)
	sed -i "s|$(HOME)|IAMUName|" src/np_main.cpp

install:
	@printf "%b" "$(BCYAN)Installing next-prayer...$(WHITE)\n"
	mkdir -p $(DESTDIR)$(LOCAL_PREFIX)/bin
	python3 src/np_fetch.py
	cp -u $(BIN) $(DESTDIR)$(LOCAL_PREFIX)/bin/
	cp -u src/next-prayer $(DESTDIR)$(LOCAL_PREFIX)/bin/
	cp -u src/np_fetch.py $(DESTDIR)$(LOCAL_PREFIX)/bin/
	mkdir -p $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/
	sed "s/VERSION/$(VERSION)/" src/next-prayer.1 > $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	@printf "%b" "$(CYAN)next-prayer$(GREEN) Installed Successfully!$(NC)\n\n"

uninstall:
	@printf "%b" "$(BYELLOW)Uninstalling next-prayer...$(WHITE)\n"
	rm -rf $(DESTDIR)$(LOCAL_PREFIX)/share/next-prayer
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/next-prayer
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_main
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_fetch.py
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_config.py
	@printf "%b" "$(CYAN)next-prayer$(GREEN) uninstalled.$(NC)\n\n"

clean:
	@printf "%b" "$(BYELLOW)Cleaning...$(WHITE)\n"
	rm -rf $(OBJ) $(BIN)
	@printf "%b" "$(GREEN)Cleaning done.$(NC)\n"

.PHONY: all install uninstall clean
