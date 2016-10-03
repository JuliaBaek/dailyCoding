#include "QuizResult.h"

QuizResult::QuizResult()
{
	scoreMap.clear();
}
QuizResult::~QuizResult()
{
	scoreMap.clear();
}
bool QuizResult::scoreProcess()
{
	if( !inputCountAndAnswers() )
	{
		return false;
	}
	validateAnswer();
	printScoreOfQuiz();
	return true;
}
bool QuizResult::inputCountAndAnswers()
{
	int count = 0;
	std::cin>>count;
	if( count <= 0 )
	{
		std::cout<<"ERROR: count value is less than 0"<<std::endl;
		return false;
	}

	bool ret = true;
	for( int i = 0; i< count ; i++)
	{
		std::string str = "";
		std::cin>>str;
		int strLen = str.size();
		if( 0 >= strLen || 80 < strLen )
		{
			std::cout<<"ERROR"<<std::endl;
			ret = false;
			break;
		}
		scoreMap.insert( std::pair<std::string, int>( str, 0 ));	
	}
	return ret;
}

void QuizResult::validateAnswer()
{
	std::map< std::string, int>::iterator it = scoreMap.begin();
	std::map< std::string, int>::iterator itEnd = scoreMap.end();

	for( ; it!=itEnd; ++it )
	{
		it->second = calculator( it->first );	
	}
}

int QuizResult::calculator( std::string answer )
{
	int i = 0;
	int result = 0;
	int score = 0;
	while( answer[i] != '\0' )
	{
		switch( toupper(answer[i]) )
		{
			case 'O' :
				score ++;
				break;
			case 'X' :
				score = 0;
				break;	
			default :
				break;
		}
		result += score;
	}	
	return result;
}
void QuizResult::printScoreOfQuiz()
{
	std::map< std::string, int>::iterator it = scoreMap.begin();
	std::map< std::string, int>::iterator itEnd = scoreMap.end();

	for( ; it!=itEnd; it++)
	{
		std::cout<< it->second<<std::endl;	
	}
}
