#include "RawMaterial.h"

void RawMaterial::show() {
	cout << "Raw material name: " << setw(16) << name << "\t" 
		<< "price: "<< setw(7) << price << endl;
}