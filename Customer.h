#pragma once
#include "PerInRes.h"

class Customer : public PerInRes
{
	friend class Manager;
private:
	int id = 0;//载入vector<Customer> clist的时候（readFile之后），要把id=clist.capacity()+1;
	double totalPrice = 0;
	double profits = 0;
	vector<Dishes> dishesBasket;
	
	vector<Dishes> menu;
	vector<Customer> clist;
	void outputClist(vector<Customer> clist, string address);
	vector<Customer> loadClist(string address);
	// 加菜
	// 先判断是不是menu里的菜
	// 再判断在不在在菜篮子里，不能加同样的菜
	// 根据ID或者name创造一个dish加到dishBasket里
	// totoalprice加上新加的菜的单价
	// profit += price - cost
	// 加到菜篮子里以后，dishes d.numberOrdered得加一
	vector<Dishes> addDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void addDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void addDIshByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);

	// 减菜
	// totoalprice减去刚删去菜的单价
	// profit -= price - cost
	// 减掉菜后，dishes d.numberOrdered减一
	vector<Dishes> deleteDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void deleteDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void deleteDishByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);

	// 查看已点的菜
	// 输出菜的id,菜的名称，原材料以及每个菜的单价
	// 最后一行显示已点菜的总价
	void showDishesBasket(vector<Dishes> dishesBasket);

	//买单check-out
	//输出客户的id，吃的菜（id和菜名，单价）,总价
	void check_out(vector<Dishes> dishesBasket,vector<Dishes>menu);

	//将customer c加入到vector<Customer> clist里;
	vector<Customer> addCustomer(Customer &c);

	//show customer's dishbasket，这个是给manager用的，和customer自己的showDishesBasket不一样
	string getDishesInBasket(vector<Dishes> d) {
		string dishName = "ordered dishes: ";
		if (d.empty()) return "No dish in dishesBasket";
 		for (int i = 0; i < d.size() - 1; i++) {
			dishName += (to_string(d[i].id) + "." + d[i].name + ", ");
		}
		dishName += to_string(d[d.size() - 1].id) + "." + d[d.size() - 1].name;
		return dishName;
	}

	//Show customer itself，给mananger看的;
	void showCustomer() {
			cout << id << "\t" << getDishesInBasket(dishesBasket)
			<< "\tTotal price: " << totalPrice << "\tProfits: "
			<< profits << endl;
	}

public:
	//与主函数的接口
	void CustomerMain(Customer &c) {
		menu=loadMenu("menu.txt");
		clist=loadClist("customerlist.txt");
		id = clist.size() + 1;
		cout << "\nRole: A customer in the restaurant" << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Browse the Menu" << endl;
		cout << "2. Search dishes" << endl;
		cout << "3. Add dish into DishesBasket" << endl;
		cout << "4. Delete dish from DishesBasket" << endl;
		cout << "5. Browse the DishesBasket" << endl;
		cout << "6. Check-out" << endl;

		cout << "Input an Integer between 1 to 6: ";
		int choice = getInt();
		switch (choice)
		{
		case 1:
			showMenu(menu);
			break;
		case 2:
			searchDishes(menu);
			break;
		case 3:
			dishesBasket = addDish(menu,dishesBasket);
			outputMenu(menu, "menu.txt");
			break;
		case 4:
			dishesBasket = deleteDish(menu,dishesBasket);
			outputMenu(menu, "menu.txt");
			break;
		case 5:
			showDishesBasket(dishesBasket);
			break;
		case 6:
			check_out(dishesBasket,menu);
			clist = addCustomer(c);
			outputClist(clist,"customerlist.txt");
			outputMenu(menu, "menu.txt");
			cout << "Customer successfully checked out!" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 7\n";
		}
		CustomerMain(c);
	}

};

