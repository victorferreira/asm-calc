all:

hello: src/hello.c
	cc -o build/hello src/hello.c
	./build/hello

cpuid: src/cpuid.s
	as -o cpuid.o src/cpuid.s
	ld -o build/cpuid cpuid.o
	rm cpuid.o
	./build/cpuid

cleanup: build/
	rm -r build/*
	rm a.out
