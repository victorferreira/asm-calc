all:

run: src/calc.c
	cc -o build/calc src/calc.c
	./build/calc

cpuid: src/cpuid.s
	as -o cpuid.o src/cpuid.s
	ld -o build/cpuid cpuid.o
	rm cpuid.o
	./build/cpuid

cleanup: build/
	rm -r build/*
	rm a.out
