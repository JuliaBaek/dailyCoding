all : PrimeNumber
PrimeNumber : PrimeNumber.cpp
	g++ -W -Wall -o PrimeNumber PrimeNumber.cpp
clean :
	rm -rf PrimeNumber
