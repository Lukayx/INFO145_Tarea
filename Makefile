CC=g++
CFLAGS=-Wall -std=c++17
BINS= explicitArray gapsCoding gapsPacked
PROFILEFLAGS=-g -O0 -Wall -DVERBOSE
all: clean explicitArray gapCoding gapPacked

explicitArray:
	$(CC) $(CFLAGS) -o bin/explicitArray explicitArray.cpp
gapCoding:
	$(CC) $(CFLAGS) -o bin/gapsCoding prog_2/gapCoding_array.cpp
gapPacked:
	$(CC) $(CFLAGS) -o bin/gapsPacked prog_3/gapPacked_Array.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
