#include "Divisor.h"

Divisor::Divisor()
{
	number = 0;
}

Divisor::~Divisor()
{
	positiveNumbers.clear();
}

unsigned int Divisor::findPositiveNumber()
{
	set<int>::iterator it = positiveNumbers.begin();
	set<int>::reverse_iterator rit = positiveNumbers.rbegin();
	return (*it) * (*rit);
}

bool Divisor::validatePositiveNumber( int num )
{
	if( num <= 1000000 && num >= 2 )
	{
		return true;
	}
	return false;
}

bool Divisor::validateNumberRange()
{
	if( number <= 50 )
	{
		return true;
	}
	return false;
}

void Divisor::positiveProgram()
{
	cin>>number;
	if ( !validateNumberRange() )
	{
		return;
	}

	int tmp = 0;
	for( int i = 0 ; i<number ; i++ )
	{
		cin>>tmp;
		validatePositiveNumber( tmp );
		positiveNumbers.insert(tmp);
	}
	cout <<findPositiveNumber()<<endl;
}

int main()
{
	Divisor divisor;
	divisor.positiveProgram();
}
