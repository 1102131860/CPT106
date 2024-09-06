#include "Dishes.h"
bool Dishes:: operator> (Dishes d) {
	if (numOrdered != d.numOrdered)
		return numOrdered > d.numOrdered;
	if (price - cost != d.price - d.cost)
		return price - cost > d.price - d.cost;
	else
		return id > d.id;
}

string Dishes::getRawName(vector<RawMaterial> r) {
	if (r.empty()) return "No material";
	string rawName = "";
	for (int i = 0; i < r.size() - 1; i++) {
		rawName += (r[i].name + ", ");
	}
	rawName += r[r.size() - 1].name;
	return rawName;
}

void Dishes::showWOTcost() {
	cout << "Dish id: " << setw(7) << id
		<< "\tname: " << setw(25) << name
		<< "\tprice: " << setw(7) <<price
		<< "\traw material(s): " << setw(25) << getRawName(rawVector)
		<< "\tordered time: " << setw(7) << numOrdered << endl;
}

void Dishes::showAll() {
	cout << "Dish id: " << setw(7) << id
		<< "\tname: " << setw(25) << name
		<< "\tprice: " << setw(7) << price
		<< "\tcost: " << setw(7) << cost
		<< "\traw material(s): " << setw(25) << getRawName(rawVector)
		<< "\tordered time: " << setw(7) << numOrdered << endl;
}
