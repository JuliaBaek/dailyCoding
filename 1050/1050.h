#include <stdio.h>

using namespace std;
class 1050{
	public:
		1050();
		bool createLiquidMedicine();

	private:
		bool validateName(string meterial);
		bool validatePrice(int price);
		bool medicineMaterialAndCount();
		bool insertMaterialNameAndPrice();
		bool inputMedicineMeterial();
		bool makingMedicine();
		int validateMedicine();

		map<stirng, int> meterial;
		int medicine;
		int N; //재료 수
		int M; //식의 수
};
