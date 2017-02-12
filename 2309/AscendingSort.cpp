#include "AscendingSort.h"

const int kSum = 100;
AscendingSort::~AscendingSort()
{
	numbers.clear();
}

void AscendingSort::printSort()
{
	if( numbers.size() != 7 )
		return;
	std::set<int>::iterator it = numbers.begin();
	std::set<int>::iterator itend = numbers.end();
	for( ; it!=itend; it++)
	{
		std::cout<< *it << std::endl;
	}
}

bool AscendingSort::calculatorNum()
{
	int sum = 0;
	std::set<int>::iterator it = numbers.begin();
	std::set<int>::iterator itend = numbers.end();

	for( ; it!=itend; it++ )
	{
		if( *it == needlessNum1 || *it == needlessNum2 )
		{
			continue;
		}
		sum += *it;
	}
	return ( sum==kSum )? true:false;
}

void AscendingSort::findUnnecessaryNumber()
{
	try
	{
		std::set<int>::iterator it = numbers.begin();
		std::set<int>::iterator itend = numbers.end()--;
		for( ; it != itend ; ++it )
		{
			needlessNum1 = *it;
			for( std::set<int>::iterator iter = std::next(it, 1); iter!= numbers.end(); ++iter )
			{
				needlessNum2 = *iter;
				if( calculatorNum() )
					throw true ;
			}
		}
	}
	catch ( bool ret )
	{
		numbers.erase( needlessNum1 );
		numbers.erase( needlessNum2 );
		printSort();
	}
}

bool AscendingSort::inputNum()
{
	bool ret = false;
	unsigned int num = 0;
	for(int i=0; i<9; i++ )
	{
		std::cin>>num;
		if( !validateNum( num ) )
		{
			ret = false;
			break;
		}
		numbers.insert(num);
		ret = true;
	}

	return ret;
}

bool AscendingSort::validateNum( int num )
{
	if ( num <= 0 || num > 100 )
		return false;
	return true;
}

void AscendingSort::startProgram()
{
	if( !inputNum() )
	{
		numbers.clear();
		return;
	}
	findUnnecessaryNumber();
}

int main()
{
	AscendingSort sort;
	sort.startProgram();
	return 0;
}
