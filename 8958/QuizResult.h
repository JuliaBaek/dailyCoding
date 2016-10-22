#ifndef __QUIZ_RESULT_H__
#define __QUIZ_RESULT_H__
#include <iostream>
#include <deque>
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
		int calculator( std::string answer );

		std::deque< std::string > score;
};
#endif
