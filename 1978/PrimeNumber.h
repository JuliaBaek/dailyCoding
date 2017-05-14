#ifndef __PRIME_NUMBER_H__
#define __PRIME_NUMBER_H__

#include <iostream>
#include <vector>

const int MaxNumber = 1001;

using namespace std;
class PrimeNumber
{
    public:
        PrimeNumber();
        ~PrimeNumber();
        void lookForThePrimeNumber();

    private:
        void eratosthenes();
        bool input();
        void printNumberOfPrimeNumber();

        int quantity;
        bool primeNumber[MaxNumber];
        vector<int> inputNumber;
};

#endif
