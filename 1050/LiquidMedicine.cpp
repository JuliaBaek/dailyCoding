#include "LiquidMedicine.h"
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string.h>
#include <string>

#define FAIL -1
LiquidMedicine::LiquidMedicine()
{
	numberOfMeterials = 0;
	M = 0;
}
bool LiquidMedicine::validatenumberOfMeterialsame(string elem)
{
	bool ret = true;
	map<string, int>::iterator itMap = meterial.begin();
	for(  ; itMap!=meterial.end(); itMap++)
	{
		if(itMap->first.compare(elem) == 0 )
		{
			ret = false;
			break;
		}
	}	
	if( elem.length() > 50 )
	{
		return ret && false;
	}
	return ret && true;
}
bool LiquidMedicine::validatePrice(int price)
{
	return price > 100? false : true;
}
void LiquidMedicine::createLiquidMedicine()
{
	if(!inputMedicineMaterial())
	{
		return;
	}

	if(!makingMedicine())
	{
		cout<<FAIL<<endl;
		return;
	}
	cout<<validateMedicine(meterial[name])<<endl ;
}
int LiquidMedicine::validateMedicine(int medicine)
{
	return ( medicine > 1000000000 )? 1000000001 : medicine;
}
bool LiquidMedicine::makingMedicine()
{
	map<string, vector<string> >::iterator itMap = recipes.begin();
	map<string, vector<string> >::iterator itEnd = recipes.end();
	for( ; itMap != itEnd; ++itMap)
	{
		name = itMap->first;
		vector<string> vec = itMap->second;
		int sum = 0;
		for(int i = 0; i<(int)vec.size(); i++)
		{
			int cnt = atoi((vec[i].substr(0,1).c_str()));
			string elem = vec[i].substr(1);
			map<string, int>::iterator it = meterial.find(elem);
			if( it == meterial.end())
			{
				return false;
			}
			sum += (cnt*meterial[elem]);
		}
		meterial.insert(make_pair(name, sum) );
	}
	return true;
}
bool LiquidMedicine::inputMedicineMaterial()
{
	if(!medicineMaterialAndCount())
	{
		return false;
	}
	if(!insertMaterialNameAndPrice())
	{
		return false;
	}
	if(!inputRecipe())
	{
		return false;
	}
	return true;
}

bool LiquidMedicine::inputRecipe()
{
	char recipe[50]={0,};
	for( int i =0; i<M; i++)
	{
		cin>>recipe;
		if( strlen(recipe) > 50 )
		{
			return false;
		}
		char* pch;
		pch = strtok( recipe, "=");
		name = pch;
		pch = strtok( NULL, "+");
		while( pch != NULL )
		{
			recipes[name].push_back(pch);
			pch = strtok( NULL, "+");
		}
	}
	return true;
}

bool LiquidMedicine::medicineMaterialAndCount()
{
	cin>>numberOfMeterials>>M;
	
	if( numberOfMeterials < 1 || numberOfMeterials > 50 )
	{
		return false;
	}
	return ( M >= 0 && M <= 50 )? true : false;
}
bool LiquidMedicine::insertMaterialNameAndPrice()
{
	bool ret = true;
	string name = "";
	int price = 0;
	for(int i=0; i<numberOfMeterials; i++)
	{
		cin>>name;
		cin>>price;
		if(!validatenumberOfMeterialsame(name))
		{
			ret = false;
			break;
		}
		if(!validatePrice(price))
		{
			ret = false;
			break;
		}
		meterial.insert(make_pair(name, price));
	}
	return ret;
}

int main()
{
	LiquidMedicine medicine;
	medicine.createLiquidMedicine();
	return 0;
}

