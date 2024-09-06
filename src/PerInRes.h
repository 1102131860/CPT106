#pragma once
#include<fstream>
#include"Dishes.h";

class PerInRes
{
private:
	vector<Dishes> menu;

protected:
	//show Menu; virtual, polymorphism 
	//cost will not be shown at this function while override function can
	virtual void showMenu(vector<Dishes> menu);
	virtual void showMenuNomally(vector<Dishes> t);
	virtual void showPopularDishes(vector<Dishes> t); //show dishes according to populartiy
	vector<Dishes> sort(vector<Dishes> t);//sort dishes according to popularity

	//show dishes which contains some key words without showing cost
	//virtual, polymorphism
	virtual void searchDishes(vector<Dishes> t);
	virtual void searchDishesByID(vector<Dishes> t, int did);
	virtual void searchDishesByName(vector<Dishes> t, string name);
	//show all dishes containing specific raw material
	virtual void searchDishesByRaw(vector<Dishes> t, string RawMaterialName);
	//show all dishes with specific price
	virtual void searchDishesByPrice(vector<Dishes> t, double price);


	//judge whether a dish exists in a vector by id or name
	bool findDishesByID(vector<Dishes> t, int did);
	bool findDishesByName(vector<Dishes> t, string name);

	//read information about dishes and raw materials from files
	vector<Dishes> loadMenu(string menuaddress);
	vector<RawMaterial> loadRlist(string address);

	//output information about dishes and raw materials into files
	void outputMenu(vector<Dishes> menu, string address);
	void outputRlist(vector<RawMaterial> rlist, string address);


public:
	//swift stream into specific data type and return it
	//int, string, double,
	int getInt();//return positive integer, otherwise -1
	string getString();//return string in a line
	double getPosDouble();//return positive double, otherwise -1
	vector<string> stringSplit(string str, char cr);//split string and allocate them into vector
};

