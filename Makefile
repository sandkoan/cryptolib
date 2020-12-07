CC = gcc

CFLAGS = -std=c99 -Wall 

INC_DIR = include
SRC_DIR = src
BIN_DIR = bin

TARGET = main

all: $(TARGET)

$(TARGET): $(SRC_DIR)/$(TARGET).c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(SRC_DIR)/$(TARGET).c

clean:
	$(RM) $(BIN_DIR)/$(TARGET)
