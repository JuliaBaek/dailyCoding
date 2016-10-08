all : LiquidMedicine
LiquidMedicine : LiquidMedicine
	gcc -W -Wall -o LiquidMedicine LiquidMedicine.o
LiquidMedicine.o : LiquidMedicine.cpp
	gcc -I /usr/include/c++/4.8/ -c LiquidMedicine.o LiquidMedicine.cpp 
clean :
	rm -rf *.o LiquidMedicine
