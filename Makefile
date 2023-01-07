# OpenSTG MAKEFILE


all: main
	-./main

main: build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/danmaku.o
	gcc build/main.o build/player.o build/resman.o build/stage.o build/bullet.o build/logger.o build/danmaku.o -o main -g -lraylib -lm -lGL -lpthread -ldl -lrt -lX11

build/main.o: src/main.c
	gcc src/main.c -c -o build/main.o

build/player.o: src/player.c
	gcc src/player.c -c -o build/player.o

build/resman.o: src/resman.c
	gcc src/resman.c -c -o build/resman.o

build/stage.o: src/stage.c
	gcc src/stage.c -c -o build/stage.o

build/bullet.o: src/bullet.c
	gcc src/bullet.c -c -o build/bullet.o

build/logger.o: src/logger.c
	gcc src/logger.c -c -o build/logger.o

build/enemy.o: src/enemy.c
	gcc src/enemy.c -c -o build/enemy.o

build/danmaku.o: src/danmaku.c
	gcc src/danmaku.c -c -o build/danmaku.o

.PHONY:clean
clean:
	-rm -fr build/* main