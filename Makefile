CC=gcc
INC_DIR=include

run: compile
	./main

compile: src/main.c
	gcc -std=c99 -Wall src/main.c -o main
