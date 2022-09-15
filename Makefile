# next-prayer - Next Islamic prayer
.POSIX:  all install uninstall clean

VERSION := $(shell awk '/VERSION\[\] =/ {print $$5}' src/np_main.cpp | sed "s/\"\|;//g")
SHELL := /bin/bash

SRC := src/*.cpp
OBJ := *.o
TARGET := np_main

CC := g++
FLAGS := -std=c++2a -pedantic -O3 -static

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

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(TARGET)
	@printf "%b" "$(GREEN)Target compiled successfully!$(NC)\n"

$(OBJ): $(SRC)
	sed -i "s|IAMUName|$(HOME)|" src/np_main.cpp
	$(CC) $(FLAGS) -c $(SRC)
	sed -i "s|$(HOME)|IAMUName|" src/np_main.cpp

install:
	mkdir -p $(DESTDIR)$(LOCAL_PREFIX)/bin
	python3 src/np_fetch.py
	cp -f $(TARGET) $(DESTDIR)$(LOCAL_PREFIX)/bin/
	cp -f src/next-prayer $(DESTDIR)$(LOCAL_PREFIX)/bin/
	cp -f src/np_fetch.py $(DESTDIR)$(LOCAL_PREFIX)/bin/
	mkdir -p $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/
	sed "s/VERSION/$(VERSION)/" src/next-prayer.1 > $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	chmod 750 $(DESTDIR)$(HOME)
	chmod 754 $(DESTDIR)$(LOCAL_PREFIX)
	chmod 754 $(DESTDIR)$(LOCAL_PREFIX)/bin
	chmod 754 $(DESTDIR)$(LOCAL_PREFIX)/share
	@printf "%b" "$(CYAN)next-prayer$(GREEN) installed successfully!$(NC)\n"

uninstall:
	rm -rf $(DESTDIR)$(LOCAL_PREFIX)/share/next-prayer
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/share/man/man1/next-prayer.1
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/next-prayer
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_main
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_fetch.py
	rm -f $(DESTDIR)$(LOCAL_PREFIX)/bin/np_config.py
	@printf "%b" "$(CYAN)next-prayer$(GREEN) uninstalled.$(NC)\n"

clean:
	rm -rf $(OBJ) $(TARGET)
	@printf "%b" "$(GREEN)Cleaning done.$(NC)\n"

.PHONY: all install uninstall clean
