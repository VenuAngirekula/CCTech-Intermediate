SHELL := /bin/bash

.PHONY: all

all: build 

.PHONY: build

build: cat.cpp
	g++ cat.cpp -o cat
	
TestCase1: cat
	./cat

TestCase2: cat 
	diff <(./cat folder1) <(cat folder1)


TestCase3: cat 
	diff <(./cat file1) <(cat file1)

TestCase4: cat 
	diff <(./cat file1 folder1 ) <(cat file1 folder1)

TestCase5: cat 
	diff <(./cat file3 ) <(cat file3)

TestCase6: cat 
	diff <(./cat fodler1 file3 file1) <(cat fodler1 file3 file1)

.PHONY: clean

clean:
	$(RM) cat *.o