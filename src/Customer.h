#pragma once
#include "PerInRes.h"

class Customer : public PerInRes
{
	friend class Manager;
private:
	int id = 0;//when loading vector<Customer> clist£¨After readFile£©£¬id=clist.capacity()+1;
	double totalPrice = 0;
	double profits = 0;
	vector<Dishes> dishesBasket;
	vector<Dishes> menu;
	vector<Customer> clist;

	void outputClist(vector<Customer> clist, string address);
	vector<Customer> loadClist(string address);
	/* add dish
	 first check whether the dish is in the menu
	then check whether the dish have been ordered
	last add the dish to dish Basket£¨order£©
	the order time of dish plus 1
	 */
	vector<Dishes> addDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void addDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void addDIshByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);

	vector<Dishes> deleteDish(vector<Dishes>& menu,vector<Dishes> dishesBasket);
	void deleteDishByID(vector<Dishes>& menu, vector<Dishes>& dishesBasket,int did);
	void deleteDishByName(vector<Dishes>& menu, vector<Dishes>& dishesBasket,string name);
	//check ordered dish
	//dishes'id,name,price and totalprice. Change the ordered times of dished
	void showDishesBasket(vector<Dishes> dishesBasket);

	//check-out
	//output customer's id£¬dishes'id,name,price and totalprice. Change the ordered times of dished. 
	void check_out(vector<Dishes> dishesBasket,vector<Dishes>menu);

	//push customer c into vector<Customer> clist;
	vector<Customer> addCustomer(Customer &c);

	//show customer's dishbasket£¬manager use thatdifferent from customer's show DishesBasket
	string getDishesInBasket(vector<Dishes> d);

	//Show customer itself£¬show mananger;
	void showCustomer();

public:
	//Interface with main function
	void CustomerMain(Customer& c);
};

