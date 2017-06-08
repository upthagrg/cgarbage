default: all

all: object test0

object:
	gcc ./garbage.h -c
test0:
	gcc garbage_test.c -o test0
test: test0
	valgrind ./test0
clean:
	rm -f ./test0 
	rm -f garbage.h.gch
