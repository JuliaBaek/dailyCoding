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
	bool ret = false;
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
	map<string, vector<string> >::reverse_iterator ritMap = recipes.rbegin();
	map<string, vector<string> >::reverse_iterator ritEnd = recipes.rend();
	for( ; ritMap != ritEnd; ritMap++)
	{
		string met = ritMap->first;
		vector<string> vec = ritMap->second;
		int sum = 0;
		for(int i =0; i<(int)vec.size(); i++)
		{
			string elem = vec[i];
			int cnt = atoi((elem.substr(0,1).c_str()));
			map<string, int>::iterator it = meterial.find(ritMap->first);
			if( it != meterial.end())
			{
				return false;
			}
			sum += (cnt*meterial[ritMap->first]);
		}
		meterial.insert(make_pair(name, sum) );
	}
	name = (--ritMap)->first;
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
		pch = strtok( recipe, "+");
		while( pch != NULL )
		{
			recipes[pch].push_back(pch);
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
		cin>>name>>price;
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

