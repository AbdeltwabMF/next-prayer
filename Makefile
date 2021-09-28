# nxprayer - Next Islamic prayer
.POSIX:

include config.mk

SRC = lapi.cpp

all: lapi

lapi: ${SRC}
	g++ ${WFLAGS} ${DFLAGS} ${OFLAGS} ${CPP} -o lapi ${SRC}

install: lapi
	mkdir -p ${DESTDIR}${CONFIG}/nxprayer
	cp -i ex.json ${DESTDIR}${CONFIG}/nxprayer/params.json
	mkdir -p ${DESTDIR}${PREFIX}/share/nxprayer/calendar/{1..12}
	sed -i "s|^params_path.*|params_path = \"${CONFIG}/nxprayer/params.json\"|g" ./rapi.py
	python3 rapi.py
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f lapi ${DESTDIR}${PREFIX}/bin
	cp -f nxprayer ${DESTDIR}${PREFIX}/bin
	mkdir -p ${DESTDIR}${MPREFIX}/man1
	cp -f nxprayer.1 ${DESTDIR}${MPREFIX}/man1
	chmod 644 ${DESTDIR}${MPREFIX}/man1/nxprayer.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/nxprayer
	rm -f ${DESTDIR}${PREFIX}/bin/lapi
	rm -f ${DESTDIR}${MPREFIX}/man1/nxprayer.1
	rm -rf ${DESTDIR}${PREFIX}/share/nxprayer

clean:
	rm -f lapi

.PHONY: all clean install uninstall
