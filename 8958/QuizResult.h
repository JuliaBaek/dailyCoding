#ifndef __QUIZ_RESULT_H__
#define __QUIZ_RESULT_H__
#include <iostream>
#include <map>
#include <string>
#include <string.h>

class QuizResult
{
	public:
		QuizResult();
		~QuizResult();
		bool scoreProcess();

	private:
		bool inputCountAndAnswers();
		void printScoreOfQuiz();
		void validateAnswer();
		int calculator( std::string answer );

		std::map< std::string, int> scoreMap;
};
#endif
