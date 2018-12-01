CC = gcc
default: test

all: test

test: garbage_test.c garbage.h
	$(CC) garbage_test.c -o test
run_test: test
	valgrind ./test
clean:
	rm -f ./test
