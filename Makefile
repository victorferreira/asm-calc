all:

run: src/main.c
	cc -o build/main src/main.c
	./build/main

cpuid: src/cpuid.s
	as -o cpuid.o src/cpuid.s
	ld -o build/cpuid cpuid.o
	rm cpuid.o
	./build/cpuid

cleanup: build/
	rm -r build/*
	rm a.out
