# OpenSTG MAKEFILE


all: openstg
	-./openstg

openstg: build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/ui.o build/point.o build/util.o build/bullethandle.o build/pointhandle.o
	gcc build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/ui.o build/point.o build/util.o build/bullethandle.o build/pointhandle.o -o openstg -g -lraylib -lm -lGL -lpthread -ldl -lrt -lX11

build/main.o: src/main.c
	cc src/main.c -c -o build/main.o

build/player.o: src/player.c
	cc src/player.c -c -o build/player.o

build/resman.o: src/resman.c
	cc src/resman.c -c -o build/resman.o

build/stage.o: src/stage.c
	cc src/stage.c -c -o build/stage.o

build/bullet.o: src/bullet.c
	cc src/bullet.c -c -o build/bullet.o

build/bullethandle.o: src/bullethandle.c
	cc src/bullethandle.c -c -o build/bullethandle.o

build/logger.o: src/logger.c
	cc src/logger.c -c -o build/logger.o

build/enemy.o: src/enemy.c
	cc src/enemy.c -c -o build/enemy.o

build/ui.o: src/ui.c
	cc src/ui.c -c -o build/ui.o

build/point.o: src/point.c
	cc src/point.c -c -o build/point.o

build/pointhandle.o: src/pointhandle.c
	cc src/pointhandle.c -c -o build/pointhandle.o

build/util.o: src/util.c
	cc src/util.c -c -o build/util.o

.PHONY:clean
clean:
	-rm -fr build/* openstg