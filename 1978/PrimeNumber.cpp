#include "PrimeNumber.h"

PrimeNumber::PrimeNumber()
{
    primeNumber[0] = false;
    primeNumber[1] = false;

    for(int i=2 ; i<MaxNumber; i++ )
    {
        primeNumber[i] = true;
    }
    eratosthenes();
}

PrimeNumber::~PrimeNumber()
{
    fill( &primeNumber[0], &primeNumber[MaxNumber], false);
    inputNumber.clear();
}

void PrimeNumber::lookForThePrimeNumber()
{
    if( !input() )
        return;

    for (vector<int>::iterator it = inputNumber.begin() ; it != inputNumber.end(); ++it)
    {
        if( primeNumber[ *it ] )
            quantity++;
    }
    printNumberOfPrimeNumber();
}

bool PrimeNumber::input()
{
    int N = 0;
    int M = 0;

    cin>>N;
    if( N > 100 )
        return false;

    for( int i=0; i<N ; i++ )
    {
        cin>>M;
        if( M > 1000 )
            return false;
        inputNumber.push_back(M);
    }

    return true;
}

void PrimeNumber::printNumberOfPrimeNumber()
{
    cout<<quantity<<endl;
}

void PrimeNumber::eratosthenes()
{
    for( int i=2; i<MaxNumber; i++ )
    {
        if( !primeNumber[i] )
            continue;
        primeNumber[i] = true;
        for( int j= i*2; j<MaxNumber; j=j+i )
        {
            primeNumber[j] = false;
        }
    }
}

int main()
{
    PrimeNumber prime;
    prime.lookForThePrimeNumber();
    return 0;
}
