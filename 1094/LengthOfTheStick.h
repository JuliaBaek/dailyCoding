#ifndef __LENGTH_OF_THE_STICK_H__
#define __LENGTH_OF_THE_STICK_H__
#include <stdio.h>
#include <vector>

using namespace std;
class LengthOfTheStick
{
	public:
		LengthOfTheStick();
		~LengthOfTheStick();
		void inputData();

	private:
		int calculator();
		void print();
		void makeStickLength();

		int stickSize;
		int cnt;
		vector<int> newStick;
};
#endif

