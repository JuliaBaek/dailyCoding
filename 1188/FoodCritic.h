#ifndef __FOOD_CRITIC_H__
#define __FOOD_CRITIC_H__

#include <iostream>
using namespace std;

class FoodCritic
{
	public:
		void startProgram();

	private:
		bool validateInput();
		int numberOfCutting();

		int sausages;
		int critic;

};
#endif
