#pragma once
#include"Chef.h";
#include"Customer.h"

class Manager : public Chef
{
private:
	vector<Customer> clist;
	vector<RawMaterial> rlist;
	vector<Dishes> menu;

	vector<RawMaterial> addRawMaterial(vector<RawMaterial> rlist);
	// create and add a new material to the rlist

	vector<RawMaterial> modifyRawMaterial(vector<RawMaterial> rlist);
	vector<RawMaterial> modifyRawMaterial(vector<RawMaterial> rlist, string r);
	//modify raw material

	void deleteRawMaterial(vector<RawMaterial>& rlist);
	void deleteRawMaterial(vector<RawMaterial>& rlist, string r);
	//delete raw material

	vector<Dishes> setDPC(vector<Dishes> menu);
	vector<Dishes> setDPCbyName(vector<Dishes> menu,string n);
	vector<Dishes> setDPCbyID(vector<Dishes> menu,int did);
	//reset the dish's price and cost
	
	void showCustomers(vector<Customer> clist);
	//view customer's infomation

	double TotalProfits(vector<Dishes> menu);
	//print the current total profit of the restaurant
	
	void searchCustomerbyDishes(vector<Customer> clist, string dishname);
	void searchCustomerbyID(vector<Customer> clist, int id);
	//search customer's infomation by id or dishes they ordered
	
	vector<Customer> addCustomer(vector<Dishes>& menu,vector<Customer> clist);
	//create and add new customer to the list

	vector<Customer> modifyCustomer(vector<Dishes>& menu, vector<Customer> clist);
	vector<Customer> modifyCustomer(vector<Dishes>& menu, vector<Customer> clist, int id);
	//modify customer's information

	void deleteCustomer(vector<Customer>& clist);
	void deleteCustomer(vector<Customer>& clist, int id);
	//delete customer's information

public:
	void ManagerMain();
	//interface for the main function

	void dealRawMaterial(vector<RawMaterial> rlist);
	//deal with raw material

	void dealDishes(vector<Dishes> menu);
	//deal with dishes

	void dealCustomer(vector<Customer> clist);
	//deal with customers
};

