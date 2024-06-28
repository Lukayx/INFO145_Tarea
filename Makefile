CC=g++
CFLAGS=-Wall -std=c++17
BINS=problema
PROFILEFLAGS=-g -O0 -Wall -DVERBOSE
all: clean explicitArray gapCoding gapPacked

explicitArray:
	$(CC) $(CFLAGS) -o explicitArray explicitArray.cpp
gapCoding:
	$(CC) $(CFLAGS) -o gapsCoding gapCoding_array.cpp
gapPacked:
	$(CC) $(CFLAGS) -o gapsPacked gapPacked_Array.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
