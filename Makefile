default: test

all: test test0

test: 
	gcc garbage_test.c -o test0
	./test0
test0: 
	gcc garbage_test.c -o test0
	valgrind ./test0
clean:
	rm -f ./test0 
