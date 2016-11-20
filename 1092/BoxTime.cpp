#include "BoxTime.h"

const int CraneMaxWeight = 50;
const int MaxWeight = 1000000;
const int BoxMaxWeight = 10000;

BoxTime::BoxTime()
{
	craneWeight.clear();
	boxWeight.clear();
	craneCnt = 0;
	boxCnt = 0;
}

BoxTime::~BoxTime()
{
	craneWeight.clear();
	boxWeight.clear();
}

void BoxTime::execute()
{
	inputCondition();
	cout<<calculateMinumumTime()<<std::endl;
}

int BoxTime::calculateMinumumTime()
{
	std::set<int>::iterator itCrane = craneWeight.begin();
	std::set<int>::iterator endCrane = craneWeight.end();
	std::set<int>::iterator itBox = boxWeight.begin();
	std::set<int>::iterator endBox = boxWeight.end();

	--endCrane;
	int time = 0;
	for( ; itBox != endBox; ++itCrane )
	{
		if( itCrane == endCrane )
		{
			if( *endCrane < *itBox++ )
				return -1;
			itCrane = craneWeight.begin();
			time+=1;
			continue;
		}
		if( *itCrane >= *itBox )
			*itBox++;
	}
	return ++time;
}

bool BoxTime::inputCondition()
{
	cin>>craneCnt;
	if( craneCnt > CraneMaxWeight )
	{
		return false;
	}
	int tmp = 0;
	for( int i = 0; i< craneCnt; i++)
	{
		cin>>tmp;
		if( tmp > MaxWeight )
		{
			return false;
		}
		craneWeight.insert( tmp );
	}
	
	cin>>boxCnt;
	if( boxCnt > BoxMaxWeight )
	{
		return false;
	}
	for( int j = 0; j < boxCnt; j++ )
	{
		cin>>tmp;
		if( tmp > MaxWeight )
		{
			return false;
		}
		boxWeight.insert( tmp );
	}
	return true;	
}

int main()
{
	BoxTime boxTime;
	boxTime.execute();
}
