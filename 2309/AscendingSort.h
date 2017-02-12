#ifndef __ASCENDING_SORT_H__
#define __ASCENDING_SORT_H__

#include <iostream>
#include <set>

class AscendingSort
{
	public :
		~AscendingSort();
		void startProgram();

	private:
		void printSort();
		bool calculatorNum();
		void findUnnecessaryNumber();
		bool inputNum();
		bool validateNum( int num );

		std::set<int> numbers;
		int needlessNum1;
		int needlessNum2;
};
#endif
