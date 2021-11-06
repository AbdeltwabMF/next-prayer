# next-prayer - Next Islamic prayer
.POSIX:

include config.mk

SRC = local_api.cpp

all: local_api

local_api: $(SRC)
	g++ $(WFLAGS) $(DFLAGS) $(OFLAGS) $(CPP) -o local_api $(SRC)

install: local_api
	mkdir -p $(DESTDIR)$(CONFIG)/next-prayer
	cp -iv config.json $(DESTDIR)$(CONFIG)/next-prayer/config.json
	chown -R "$(LGUSER):$(LGUSER)" $(DESTDIR)$(CONFIG)/next-prayer
	chmod 754 $(DESTDIR)$(CONFIG)/next-prayer
	chmod 644 $(DESTDIR)$(CONFIG)/next-prayer/config.json
	mkdir -p $(DESTDIR)$(LPREFIX)/share/next-prayer/calendar/{2021..2026}/{1..12}
	sed -i "s|^config_file.*|config_file = \"$(DESTDIR)$(CONFIG)/next-prayer/config.json\"|g" remote_api.py
	sed -i "s|^data_path.*|data_path = \"$(DESTDIR)$(LPREFIX)/share/next-prayer/calendar\"|g" remote_api.py
	python3 remote_api.py
	sed -i "s|^config_file.*|config_file = \"$(CONFIG)/next-prayer/config.json\"|g" remote_api.py
	sed -i "s|^data_path.*|data_path = \"$(LPREFIX)/share/next-prayer/calendar\"|g" remote_api.py
	chown -R "$(LGUSER):$(LGUSER)" $(DESTDIR)$(LPREFIX)/share/next-prayer
	chmod -R 754 $(DESTDIR)$(LPREFIX)/share/next-prayer
	mkdir -p $(DESTDIR)$(LPREFIX)/bin
	cp -f local_api $(DESTDIR)$(LPREFIX)/bin
	cp -f remote_api.py $(DESTDIR)$(LPREFIX)/bin
	cp -f next-prayer $(DESTDIR)$(LPREFIX)/bin
	chmod 755 $(DESTDIR)$(LPREFIX)/bin/local_api
	chown "$(LGUSER):$(LGUSER)" $(DESTDIR)$(LPREFIX)/bin/remote_api.py
	chmod 755 $(DESTDIR)$(LPREFIX)/bin/next-prayer
	sed "s/VERSION/$(VERSION)/g" < next-prayer > $(DESTDIR)$(LPREFIX)/bin/next-prayer
	mkdir -p $(DESTDIR)$(MAN)/man1
	sed "s/VERSION/$(VERSION)/g" < next-prayer.1 > $(DESTDIR)$(MAN)/man1/next-prayer.1
	chmod 644 $(DESTDIR)$(MAN)/man1/next-prayer.1

uninstall:
	rm -f $(DESTDIR)$(LPREFIX)/bin/next-prayer
	rm -f $(DESTDIR)$(LPREFIX)/bin/local_api
	rm -f $(DESTDIR)$(LPREFIX)/bin/remote_api.py
	rm -f $(DESTDIR)$(MAN)/man1/next-prayer.1
	rm -rf $(DESTDIR)$(LPREFIX)/share/next-prayer

clean:
	rm -f local_api

.PHONY: all clean install uninstall
