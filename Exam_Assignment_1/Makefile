#!/bin/bash
SHELL := /bin/bash

.PHONY: all 
all: build run

.PHONY: build
build: dojo.cpp fileNameSelector.h TestingFunction.h
	g++ dojo.cpp -o dojo

run: dojo
	./dojo
	
.PHONY: clean
clean:
	$(RM) dojo *.o