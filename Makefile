default: test

all: test test0

test: 
	gcc garbage_test.c -o test
	./test
test0: 
	gcc garbage_test.c -o test0
	valgrind ./test0
clean:
	rm -f ./test ./test0
