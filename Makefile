.PHONY: all
all: main

main: main.o reverse.o truncate.o
	cc -o pacman-anim main.o reverse.o truncate.o

main.o: src/main.c
	cc -c src/main.c -o main.o

reverse.o: src/reverse.c
	cc -c src/reverse.c -o reverse.o

truncate.o: src/truncate.c
	cc -c src/truncate.c -o truncate.o

.PHONY: clean
clean:
	rm -f main.o reverse.o truncate.o

.PHONY: install
install:
	mv pacman-anim /usr/bin/pacman-anim
