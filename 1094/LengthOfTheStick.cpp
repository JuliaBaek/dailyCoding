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

LengthOfTheStick::LengthOfTheStick()
{
	cnt = 0;
	newStick.clear();
	stickSize = 0;
}
LengthOfTheStick::~LengthOfTheStick()
{
	if( !newStick.empty() )
		newStick.clear();
}
int LengthOfTheStick::calculator()
{
	int sum = newStick[0];
	int indexShort = 0;
	for( int i = 1 ; i<(int)newStick.size(); i++)
	{
		sum += newStick[i];
		if( newStick[i] < newStick[i-1] )
		{
			indexShort = i;
		}
	}
	int middleSize = 0;
	if( sum > stickSize )
	{
		middleSize = newStick[indexShort] / 2 ;
		newStick[indexShort] = middleSize;
		if( (sum - middleSize) < stickSize )
		{
			newStick.push_back(middleSize);
		}
	}
	cnt++;
	return sum-middleSize;
}

void LengthOfTheStick::makeStickLength()
{
	while(calculator() != stickSize);
	print();
}
void LengthOfTheStick::inputData()
{
	FILE* fp = fopen("file.txt","rt");
	if( fp == NULL )
	{
		return;
	}

	int leng;
	while( fscanf(fp, "%d\n", &leng) > 0 )
	{
		newStick.push_back(64);
		cnt = 0;
		if( leng > 64 )
			break;
		stickSize = leng;
		makeStickLength();
		newStick.clear();
	}	
	fclose(fp);
}

void LengthOfTheStick::print()
{
	printf("%d\n", cnt);
}
int main()
{
	LengthOfTheStick* stick = new LengthOfTheStick() ;
	stick->inputData();
	return 0;
}
