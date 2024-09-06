#pragma once
#include"PerInRes.h";

class Chef : public PerInRes
{
private:
	vector<RawMaterial> rlist;
	vector<Dishes> menu;

protected:
	//browse all the raw material information
	void browseRawMateroal(vector<RawMaterial> list);

	//search raw material information
	void searchRawMaterial(vector<RawMaterial> list);//using inputRawMaterialName()
	void searchRawMaterial(vector<RawMaterial> list, string rname);//based on name

	//check menu
	//all the information in the menu will be used
	void showMenu(vector<Dishes> t) override;
	void showPopularDishes(vector<Dishes> t) override; //show based on popularity

	//search all the dishes information
	void searchDishes(vector<Dishes>) override;
	void searchDishesByID(vector<Dishes> t, int did) override;
	void searchDishesByName(vector<Dishes> t, string name) override;
	void searchDishesByRaw(vector<Dishes> t, string RawMaterialName) override;//show all the dishes with input name
	void searchDishesByPrice(vector<Dishes> t, double price) override;//show all the dishes with input price

	//add dishes in the menu
	//check whether the dish already exist
	vector<Dishes> addDishes(vector<Dishes> menu);

	//modify the dishes including all information
	//searching based on id and name
	vector<Dishes> modifyDishes(vector<Dishes> menu);//using DishesID() and inputRawMaterialName();

	//delete dishes by id and name
	vector<Dishes> deleteDishes(vector<Dishes> menu);
	vector<Dishes> deleteDishesByID(vector<Dishes> menu, int did);
	vector<Dishes> deleteDishesByName(vector<Dishes> menu, string dname);


public:
	//interface with main function
	void ChefMain();
};

