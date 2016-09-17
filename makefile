all : test
test : test.cpp
	gcc -W -Wall -o test test.cpp
clean :
	rm -rf *.o *.a test
