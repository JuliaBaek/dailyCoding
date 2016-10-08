#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
class LiquidMedicine{
	public:
		LiquidMedicine();
		void createLiquidMedicine();

	private:
		bool validatenumberOfMeterialsame(string elem);
		bool validateName(string meterial);
		bool validatePrice(int price);
		bool medicineMaterialAndCount();
		bool insertMaterialNameAndPrice();
		bool inputMedicineMaterial();
		void makingMedicine();
		int validateMedicine(int medicine);
		bool inputRecipe();

		map<string, int> meterial;
		map<string, vector<string> > recipes;
		string name;
		int numberOfMeterials; //재료 수
		int M; //식의 수
};
