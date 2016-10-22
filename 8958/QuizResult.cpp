#include "QuizResult.h"

QuizResult::QuizResult()
{
	score.clear();
}
QuizResult::~QuizResult()
{
	score.clear();
}
bool QuizResult::scoreProcess()
{
	if( !inputCountAndAnswers() )
	{
		return false;
	}
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
		score.push_back( str );
	}
	return ret;
}
int QuizResult::calculator( std::string answer )
{
	int i = 0;
	int result = 0;
	int score = 0;
	while( answer[i] != '\0' )
	{
		switch( answer[i] )
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
		i++;
	}	
	return result;
}
void QuizResult::printScoreOfQuiz()
{
	std::deque< std::string >::iterator it = score.begin();

	for( ; it < score.end() ; it++ )
	{
		std::cout<< calculator( *it )<<std::endl;
	}
}
