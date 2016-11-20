#ifndef __BOX_TIME_H__
#define __BOX_TIME_H__
#include <iostream>
#include <set>

using namespace std;
class BoxTime
{
	public:
		BoxTime();
		~BoxTime();
		void execute();

	private:
		bool inputCondition();
		int calculateMinumumTime();

		set<int> craneWeight;
		set<int> boxWeight;
		unsigned int craneCnt;
		unsigned int boxCnt;

};

#endif
