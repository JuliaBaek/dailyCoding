#include "QuizResult.h"
#include <iostream>

int main()
{
	QuizResult test;
	if( !test.scoreProcess() )
	{
		std::cout<<"FAIL"<<std::endl;
	}
	std::cout<<"SUCCESS"<<std::endl;
	return 0;
}
