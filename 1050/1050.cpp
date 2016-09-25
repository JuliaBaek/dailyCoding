#include <stdio.h>
#include "1050.h"

#define FAIL -1

1050::1050()
{
	N = 0;
	S = 0;
}
bool 1050::validateName(string meterial)
{
	map<stirng, int>::iterator itMap;
	for( itMap = meterial.begin(); itMap!=meterial.end(); itMap++)
	{
		if(itMap->first.compare(meterial) == 0 )
		{
			printf("ERROR duplication Name\n");
			ret = false;
			break;
		}
	}	
	if( meterial.length() > 50 )
	{
		return ret && false;
	}
	return ret && true;
}
bool 1050::validatePrice(int price)
{
	return price > 100? false : true;
}
bool 1050::createLiquidMedicine()
{
	if(!inputMedicineMaterial())
	{
		return false;
	}

	//TODO : makingMedicine

	return validateMedicine() ;
}
int 1050::validateMedicine()
{
	return ( medicine > 1000000000 )? 1000000001 : medicine;
}
bool 1050::makingMedicine()
{
}
bool 1050::inputMedicineMaterial()
{
	if(!medicineMaterialAndCount())
	{
		return false;
	}
	if(!insertMaterialNameAndPrice())
	{
		return false;
	}
}

bool 1050::medicineMaterialAndCount()
{
	scanf("%d %d",&N,&M);
	
	if( N < 1 || N > 50 )
	{
		return false;
	}
	return ( M >= 0 && M <= 50 )? true : false;
}
bool 1050::insertMaterialNameAndPrice()
{
	bool ret = true;
	string name = "";
	int price = 0;
	for(int i=0; i<N; i++)
	{
		scanf("%s %d", name, &price);
		name.upper();
		if(!validateName(&name))
		{
			printf("ERROR NAME\n");
			ret = false;
			break;
		}
		if(!validatePrice(price))
		{
			printf("ERROR PRICE\n");
			ret = false;
			break;
		}
		meterial.insert(map<string,int>(string,price));
	}
	return ret;
}

int main()
{
	1050 medicine;
	if(!medicine.createLiquidMedicine())
	{
		printf("Fail to create Medicine\n");
	}
	else
	{
		printf("Success to create Medicine\n");
	}
	return 0;
}

