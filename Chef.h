#pragma once
#include"PerInRes.h";

class Chef : public PerInRes
{
private:
	vector<RawMaterial> rlist;
	vector<Dishes> menu;

protected:
	//浏览所有原材料的相关信息
	void browseRawMateroal(vector<RawMaterial> list);

	//查看要找的原材料r在不在list里
	//bool findRawMaterial(vector<RawMaterial> list);//调用继承来的inputRawMaterialName()
	//bool findRawMaterial(vector<RawMaterial> list, string rname);//根据名字

	//查看某一个原材料r的相关信息
	void searchRawMaterial(vector<RawMaterial> list);//调用继承来的inputRawMaterialName()
	void searchRawMaterial(vector<RawMaterial> list, string rname);//根据名字

	//查看菜单
	//重载overloading
	//可以看到所有有关菜谱里菜的信息，包括cost成本
	void showMenu(vector<Dishes> t) override;
	void showPopularDishes(vector<Dishes> t) override; //展示时根据受欢迎程度进行排序

	//检索包含某些关键字的菜的相关信息
	//重载overloading
	//可以看到所有有关信息，包括cost成本
	void searchDishes(vector<Dishes>) override;
	void searchDishesByID(vector<Dishes> t, int did) override;
	void searchDishesByName(vector<Dishes> t, string name) override;
	void searchDishesByRaw(vector<Dishes> t, string RawMaterialName) override;//展示所有包含原材料的名字是RawMaterialName的菜
	void searchDishesByPrice(vector<Dishes> t, double price) override;//展示所有价格是price的菜

	//增加菜单里的菜
	//先判断是不是已经在菜单里，不能加同样的菜
	//构造一个dish，然后加到menu里
	vector<Dishes> addDishes(vector<Dishes> menu);

	//修改菜单里的菜
	//菜名，原材料，单价，成本
	//根据ID或者name选择不同的函数
	vector<Dishes> modifyDishes(vector<Dishes> menu);//调用继承来的inputDishesID()和inputRawMaterialName();
	/*vector<Dishes> modifyDishesByID(vector<Dishes> menu, int did);
	vector<Dishes> modifyDishesByname(vector<Dishes> menu, string dname);*/

	//删除菜单里的菜
	//根据ID或者name选择不同的函数
	vector<Dishes> deleteDishes(vector<Dishes> menu);//调用继承来的inputDishesID()和inputRawMaterialName();
	vector<Dishes> deleteDishesByID(vector<Dishes> menu, int did);
	vector<Dishes> deleteDishesByName(vector<Dishes> menu, string dname);


public:
	//与函数的主接口
	void ChefMain() {
		menu = loadMenu("menu.txt");
		rlist = loadRlist("rawmaterial.txt");

		cout << "\nRole: A Chef in the restaurant" << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Browse RawMaterials" << endl;
		cout << "2. Search RawMaterial" << endl;
		cout << "3. Browse the Menu" << endl;
		cout << "4. Search dishes" << endl;
		cout << "5. Add dish into Menu" << endl;
		cout << "6. Modify dish in the Menu" << endl;
		cout << "7. Delete dish from the Menu" << endl;
		cout << "8. Exits" << endl;

		cout << "Input an integer between 1 to 8: ";
		int choice = getInt();
		switch (choice)
		{
		case 1:
			browseRawMateroal(rlist);
			break;
		case 2:
			searchRawMaterial(rlist);
			break;
		case 3:
			showMenu(menu);
			break;
		case 4:
			searchDishes(menu);
			break;
		case 5:
			menu = addDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 6:
			menu = modifyDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 7:
			menu = deleteDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 8:
			cout << "Chef has successfully exited out!" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 8\n";
		}
		ChefMain();
	}

};

