PREFIX = ${HOME}

DATA_DIR = ${PREFIX}/.local/share/nxprayer
BINR_DIR = ${PREFIX}/.local/bin
CNFG_DIR = ${PREFIX}/.config/nxprayer
MAN_DIR = /usr/local/share/man/man1

CPP_FLAGS = -Wall -Wextra -Wshadow -Og -g -Ofast -std=c++17 -pedantic -Wformat=2 -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wfloat-equal -D_GLIBCXX_ASSERTIONS -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fno-sanitize-recover -fstack-protector -DDEBUG -ggdb3 -fsanitize=address,undefined -fmax-errors=2 -o

all: install

install: lapi.cpp rapi.py
	g++ ${CPP_FLAGS} lapi lapi.cpp
	mkdir -p ${BINR_DIR}
	cp -f lapi ${BINR_DIR}
	cp -f nxprayer ${BINR_DIR}
	rm -rf ${DATA_DIR}
	mkdir -p ${DATA_DIR}/calendar/{1..12}
	mkdir -p ${CNFG_DIR}
	cp -i ex.json ${CNFG_DIR}/params.json
	python3 rapi.py
	mkdir -p ${MAN_DIR}
	sudo cp -f nxprayer.1 ${MAN_DIR}
	sudo chmod 644 ${MAN_DIR}/nxprayer.1

uninstall:
	rm -f ${BINR_DIR}/nxprayer
	rm -f ${BINR_DIR}/lapi
	rm -rf ${DATA_DIR}
	sudo rm -f ${MAN_DIR}/nxprayer.1

clean:
	rm -f lapi
