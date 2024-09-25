#!/usr/bin/make -f

PRODJECT_HOME := $(shell pwd)
build:
	mkdir -p out
	g++ -std=c++17 -o out/hyperflake_test src/hyperflake_test.cpp

watch:
	ls src/*.cpp | entr -c make build

run:
	./out/hyperflake_test

all: build run

.PHONY: build watch run all