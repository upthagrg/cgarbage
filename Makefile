default: test

all: test

test: 
	gcc garbage_test.c -o test0
	valgrind ./test0
clean:
	rm -f ./test0 
