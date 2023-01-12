# OpenSTG MAKEFILE


all: openstg
	-./openstg

openstg: build build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/ui.o build/point.o build/util.o build/bullethandle.o build/pointhandle.o build/enemy.o build/std01.o
	gcc build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/ui.o build/point.o build/util.o build/bullethandle.o build/pointhandle.o build/enemy.o build/std01.o -o openstg -g -lraylib -lm -lGL -lpthread -ldl -lrt -lX11

build/main.o: src/main.c src/openstg.h
	cc src/main.c -c -g -o build/main.o

build/player.o: src/player.c src/player.h
	cc src/player.c -c -g -o build/player.o

build/resman.o: src/resman.c src/resman.h
	cc src/resman.c -c -g -o build/resman.o

build/stage.o: src/stage.c src/stage.h
	cc src/stage.c -c -g -o build/stage.o

build/bullet.o: src/bullet.c src/bullet.h
	cc src/bullet.c -c -g -o build/bullet.o

build/bullethandle.o: src/bullethandle.c src/bullethandle.h
	cc src/bullethandle.c -c -g -o build/bullethandle.o

build/logger.o: src/logger.c src/logger.h
	cc src/logger.c -c -g -o build/logger.o

build/enemy.o: src/enemy.c src/enemy.h
	cc src/enemy.c -c -g -o build/enemy.o

build/ui.o: src/ui.c src/ui.h
	cc src/ui.c -c -g -o build/ui.o

build/point.o: src/point.c src/point.h
	cc src/point.c -c -g -o build/point.o

build/pointhandle.o: src/pointhandle.c src/pointhandle.h
	cc src/pointhandle.c -c -g -o build/pointhandle.o

build/util.o: src/util.c src/util.h
	cc src/util.c -c -g -o build/util.o

build/std01.o: src/test/std01.c src/test/std01.h
	cc src/test/std01.c -c -g -o build/std01.o

.PHONY:clean
clean:
	-rm -fr build/* openstg

build:
	-mkdir build