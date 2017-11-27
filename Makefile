default: test

all: object test

object:
	gcc ./garbage.h -c
test: 
	gcc garbage_test.c -o test0
	valgrind ./test0
clean:
	rm -f ./test0 
	rm -f garbage.h.gch
