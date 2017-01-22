#ifndef __DIVISOR_H__
#define __DIVISOR_H__

#include <iostream>
#include <set>
using namespace std;
class Divisor
{
	public:
		Divisor();
		~Divisor();

		void positiveProgram();

	private:
		unsigned int findPositiveNumber();
		bool validateNumberRange();
		bool validatePositiveNumber( int num );

		unsigned int number;
		set<int>  positiveNumbers;
};

#endif
