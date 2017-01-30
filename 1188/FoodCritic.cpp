#include "FoodCritic.h"

int FoodCritic::numberOfCutting()
{
	int div = critic / sausages ;
	int mod = critic % sausages ;

	if ( mod == 0 )
	{
		return sausages * (div-1);
	}
	if ( div == mod && div == 1 )
	{
		return sausages;
	}
	if ( div == 0 && sausages == critic )
	{
		return 0;
	}
	if ( div == 0 && mod != 0 )
	{
		if ( mod % critic == 0 )
		{
			return 0;
		}
		else
		{
			return mod-1;
		}
	}
	return -1;
}

bool FoodCritic::validateInput()
{
	if ( sausages < 1 || critic > 100 )
		return false;
	return true;
}

void FoodCritic::startProgram()
{
	cin>>sausages;
	cin>>critic;
	if (!validateInput())
		return;
	cout<<numberOfCutting()<<endl;
}

int main()
{
	FoodCritic food;
	food.startProgram();
	return 0;
}
