CC = gcc

CFLAGS = -std=c99 -Wall 

SRC = src
BIN = bin

TARGET = main


all: $(TARGET)

$(TARGET): $(SRC)/$(TARGET).c
	$(CC) $(CFLAGS) $(SRC)/$(TARGET).c $(wildcard src/*.c) -o $(BIN)/$(TARGET)

clean:
	$(RM) $(BIN)/$(TARGET)
