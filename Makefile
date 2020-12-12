CC = gcc

CFLAGS = -std=c99 -Wall 

INCLUDES = -Iinclude
SRC = src
BIN = bin

TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)/$(TARGET).c
	$(CC) $(INCLUDES) $(CFLAGS) -o $(BIN)/$(TARGET) $(SRC)/$(TARGET).c

clean:
	$(RM) $(BIN)/$(TARGET)
