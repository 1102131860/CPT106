#pragma once
#include "PerInRes.h"

class Customer : public PerInRes
{
	friend class Manager;
private:
	int id = 0;//����vector<Customer> clist��ʱ��readFile֮�󣩣�Ҫ��id=clist.capacity()+1;
	double totalPrice = 0;
	double profits = 0;
	vector<Dishes> dishesBasket;
	
	vector<Dishes> menu;
	vector<Customer> clist;
	void outputClist(vector<Customer> clist, string address);
	vector<Customer> loadClist(string address);
	// �Ӳ�
	// ���ж��ǲ���menu��Ĳ�
	// ���ж��ڲ����ڲ���������ܼ�ͬ���Ĳ�
	// ����ID����name����һ��dish�ӵ�dishBasket��
	// totoalprice�����¼ӵĲ˵ĵ���
	// profit += price - cost
	// �ӵ����������Ժ�dishes d.numberOrdered�ü�һ
	vector<Dishes> addDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void addDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void addDIshByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);

	// ����
	// totoalprice��ȥ��ɾȥ�˵ĵ���
	// profit -= price - cost
	// �����˺�dishes d.numberOrdered��һ
	vector<Dishes> deleteDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void deleteDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void deleteDishByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);

	// �鿴�ѵ�Ĳ�
	// ����˵�id,�˵����ƣ�ԭ�����Լ�ÿ���˵ĵ���
	// ���һ����ʾ�ѵ�˵��ܼ�
	void showDishesBasket(vector<Dishes> dishesBasket);

	//��check-out
	//����ͻ���id���ԵĲˣ�id�Ͳ��������ۣ�,�ܼ�
	void check_out(vector<Dishes> dishesBasket,vector<Dishes>menu);

	//��customer c���뵽vector<Customer> clist��;
	vector<Customer> addCustomer(Customer &c);

	//show customer's dishbasket������Ǹ�manager�õģ���customer�Լ���showDishesBasket��һ��
	string getDishesInBasket(vector<Dishes> d) {
		string dishName = "ordered dishes: ";
		if (d.empty()) return "No dish in dishesBasket";
 		for (int i = 0; i < d.size() - 1; i++) {
			dishName += (to_string(d[i].id) + "." + d[i].name + ", ");
		}
		dishName += to_string(d[d.size() - 1].id) + "." + d[d.size() - 1].name;
		return dishName;
	}

	//Show customer itself����mananger����;
	void showCustomer() {
			cout << id << "\t" << getDishesInBasket(dishesBasket)
			<< "\tTotal price: " << totalPrice << "\tProfits: "
			<< profits << endl;
	}

public:
	//���������Ľӿ�
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

