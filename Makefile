# next-prayer - Next Islamic prayer
.POSIX:

SRC = events.cpp
all: events

events: $(SRC)
	@echo "Installing events..."
	g++ -std=c++20 -o events $(SRC)

install: events
	@echo "Fetching API Data..."
	python3 fetch.py

uninstall:
	@echo "Uninstalling..."
	rm -rf $(HOME)/$(USER)/.local/share/next-prayer
	rm -rf $(HOME)/$(USER)/.local/share/man/man1/next-prayer.1
	rm -rf $(HOME)/$(USER)/.local/bin/next-prayer
	rm -rf $(HOME)/$(USER)/.local/bin/fetch.py
	rm -rf $(HOME)/$(USER)/.local/bin/config.py
	rm -rf $(HOME)/$(USER)/.config/next-prayer

clean:
	@echo "Cleaning..."
	rm -f events

.PHONY: all clean install uninstall
