# Directorios de origen y destino
PROG_2 = prog_2
PROG_3 = prog_3
SRC_DIR1 = src
SRC_DIR2 = $(PROG_2)/src
SRC_DIR3 = $(PROG_3)/src
INCLUDE_DIR1 = include
INCLUDE_DIR2 = $(PROG_2)/include
INCLUDE_DIR3 = $(PROG_3)/include
COMPILED_DIR = bin

CC = g++
CFLAGS = -Wall -std=c++17
BINS = $(COMPILED_DIR)/explicitArray $(COMPILED_DIR)/gapCoding $(COMPILED_DIR)/gapPacked

all: clean $(BINS)

$(COMPILED_DIR)/explicitArray: explicitArray.cpp $(SRC_DIR1)/*.cpp
	$(CC) $(CFLAGS) -o $@ $^

$(COMPILED_DIR)/gapCoding: $(PROG_2)/gapCoding_array.cpp $(SRC_DIR2)/*.cpp $(SRC_DIR1)/creacionProg_1.cpp
	$(CC) $(CFLAGS) -o $@ $^

$(COMPILED_DIR)/gapPacked: $(PROG_3)/gapPacked_Array.cpp $(SRC_DIR3)/*.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
