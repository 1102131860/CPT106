#pragma once
#include<fstream>
#include"Dishes.h";

class PerInRes
{
private:
	vector<Dishes> menu;

protected:
	//查看菜单
	//虚函数，多态
	//在chef和manager里可以展示菜的cost，但是customer不能看到
	virtual void showMenu(vector<Dishes> menu);
	virtual void showMenuNomally(vector<Dishes> t);
	virtual void showPopularDishes(vector<Dishes> t); //展示时根据受欢迎程度进行排序,可调用sort方法
	vector<Dishes> sort(vector<Dishes> t);

	//检索包含某些关键字的菜的相关信息，但不能显示cost
	//虚函数，多态
	//id,name,菜的原材料，价格price，
	virtual void searchDishes(vector<Dishes> t);
	virtual void searchDishesByID(vector<Dishes> t, int did);
	virtual void searchDishesByName(vector<Dishes> t, string name);
	virtual void searchDishesByRaw(vector<Dishes> t, string RawMaterialName);//展示所有包含原材料的名字是RawMaterialName的菜
	virtual void searchDishesByPrice(vector<Dishes> t, double price);//展示所有价格是price的菜


	//判断要找的菜在不在某一个vector<Dishes>里
	//根据菜的id和name
	bool findDishesByID(vector<Dishes> t, int did);
	bool findDishesByName(vector<Dishes> t, string name);

	//read files
	vector<Dishes> loadMenu(string menuaddress);
	vector<RawMaterial> loadRlist(string address);
	//vector<Customer> loadClist(string address);放在customer或mananger里，否则会报错


	//write files 
	void outputMenu(vector<Dishes> menu, string address);
	void outputRlist(vector<RawMaterial> rlist, string address);
	//void outputClist(vector<Customer> clist, string address);放在customer或mananger里，否则会报错
	

public:
	//返回某些特定的类型的值
	//请用户输入并返回
	//int, string, double,
	int getInt();//返回整数，或者-1（输入不是整数时）
	string getString();//将输入的一行作为字符串返回
	double getPosDouble();//返回正的double，或者-1（输入不是double时）
	vector<string> stringSplit(string str, char cr);//根据cr把string分解，并返回vector<string>;如果str里没有cr，就返回str

	//与主函数的接口
	//void PerInResMain();
};



