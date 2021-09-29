# nxprayer - Next Islamic prayer
.POSIX:

include config.mk

SRC = lapi.cpp

all: lapi

lapi: $(SRC)
	g++ $(WFLAGS) $(DFLAGS) $(OFLAGS) $(CPP) -o lapi $(SRC)

install: lapi
	mkdir -p $(DESTDIR)$(CONFIG)/nxprayer
	cp -f ex.json $(DESTDIR)$(CONFIG)/nxprayer/params.json
	chown -R "$(_USER):$(_USER)" $(DESTDIR)$(CONFIG)/nxprayer
	chmod 754 $(DESTDIR)/home/$(_USER)
	chmod 754 $(DESTDIR)$(CONFIG)
	chmod 754 $(DESTDIR)$(CONFIG)/nxprayer
	chmod 664 $(DESTDIR)$(CONFIG)/nxprayer/params.json
	mkdir -p $(DESTDIR)$(PREFIX)/share/nxprayer/calendar/{1..12}
	sed -i "s|^params_path.*|params_path = \"$(DESTDIR)$(CONFIG)/nxprayer/params.json\"|g" ./rapi.py
	sed -i "s|^data_path.*|data_path = \"$(DESTDIR)$(PREFIX)/share/nxprayer/calendar\"|g" ./rapi.py
	python3 rapi.py
	chown -R "$(_USER):$(_USER)" $(DESTDIR)$(PREFIX)/share/nxprayer
	chmod -R 754 $(DESTDIR)$(PREFIX)/share/nxprayer
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f lapi $(DESTDIR)$(PREFIX)/bin
	cp -f nxprayer $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/lapi
	chmod 755 $(DESTDIR)$(PREFIX)/bin/nxprayer
	mkdir -p $(DESTDIR)$(MPREFIX)/man1
	cp -f nxprayer.1 $(DESTDIR)$(MPREFIX)/man1
	chmod 644 $(DESTDIR)$(MPREFIX)/man1/nxprayer.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/nxprayer
	rm -f $(DESTDIR)$(PREFIX)/bin/lapi
	rm -f $(DESTDIR)$(MPREFIX)/man1/nxprayer.1
	rm -rf $(DESTDIR)$(PREFIX)/share/nxprayer

clean:
	rm -f lapi

.PHONY: all clean install uninstall
