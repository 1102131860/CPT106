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
	void ManagerMain() {
		rlist = loadRlist("rawmaterial.txt");
		menu = loadMenu("menu.txt");
		Customer c;
		clist = c.loadClist("customerlist.txt");
		cout << "\nRole: A Manager in the restaurant" << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Deal with Raw Material\n";
		cout << "2. Deal with Menu\n";
		cout << "3. Deal with Customer Information\n";
		cout << "4. Show current profits in total\n";
		cout << "5. Exit\n";
		
		cout << "Input an Integer between 1 to 5: ";
		int choice = getInt();
		switch (choice)
		{
		case 1:
			dealRawMaterial(rlist);
			break;
		case 2:
			dealDishes(menu);
			break;
		case 3: 
			dealCustomer(clist);
			break;
		case 4:
			cout << "Current total profits is : " << TotalProfits(menu) << endl;
			break;
		case 5:
			cout << "Manager has successfully exited out!" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 5 \n";
		}
		ManagerMain();
	}
	//interface for the main function

	void dealRawMaterial(vector<RawMaterial> rlist) {
		cout << "Choose an option:\n";
		cout << "1. Browse RawMaterial\n";
		cout << "2. Search RawMaterial\n";
		cout << "3. Add RawMaterial\n";
		cout << "4. Modify RawMaterial\n";
		cout << "5. Delete RawMaterial\n";
		cout << "6. Return to deal other things\n";
        cout << "Input an Integer between 1 to 6: ";
		int choice = getInt();
		string rwname;
		switch (choice)
		{
		case 1:
			browseRawMateroal(rlist);
			break;
		case 2:
			searchRawMaterial(rlist);
			break;
		case 3:
			rlist = addRawMaterial(rlist);
			break;
		case 4: {
			cout << "Choose an option:\n";
			cout << "1. Modify all RawMaterial\n";
			cout << "2. Modify RawMaterial according to name\n";
			cout << "3. Return\n ";
			cout << "Input an Integer between 1 to 3: ";
			choice = getInt();
			switch (choice) {
			case 1:
				rlist = modifyRawMaterial(rlist);
				break;
			case 2:
				rlist = modifyRawMaterial(rlist, rwname);
				break;
			case 3:
				dealRawMaterial(rlist);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 3\n";
			}
			break;
		}
		case 5: {
			cout << "Choose an option:\n";
			cout << "1. Delete all RawMaterial\n";
			cout << "2. Delete RawMaterial according to name\n";
			cout << "3. Return \n";
			cout << "Input an Integer between 1 to 3: ";
			choice = getInt();
			switch (choice) {
			case 1:
				deleteRawMaterial(rlist);
				break;
			case 2:
			    deleteRawMaterial(rlist, rwname);
				break;
			case 3:
				dealRawMaterial(rlist);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 3\n";
			}
			break;
		}
			
		case 6:
			outputRlist(rlist, "rawmaterial.txt");
			ManagerMain();
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 6\n";
		}
		dealRawMaterial(rlist);
	}
	//deal with raw material

	void dealDishes(vector<Dishes> menu) {
		cout << "Choose an option:\n";
		cout << "1. Browse Menu (according to popularity)\n";
		cout << "2. Search Dish\n";
		cout << "3. Add Dish\n";
		cout << "4. Modify Dish price and cost\n";
		cout << "5. Modify Menu\n";
		cout << "6. Delete Dish\n";
		cout << "7. Return to deal other things\n";

		cout << "Input an Integer between 1 to 7: ";
		string dn;
		int did = 0;
		int choice = getInt();
		switch (choice)
		{
		case 1:
			showPopularDishes(menu);
			break;
		case 2:
			searchDishes(menu);
			break;
		case 3:
			menu = addDishes(menu);
			break;
		case 4: {
			
			cout << "Choose an option:\n";
			cout << "1. Modify all Dishes' price\n";
			cout << "2. Modify Dishes' price according to name\n";
			cout << "3. Modify Dishes' price according to id\n";
			cout << "4. Return\n ";
			cout << "Input an Integer between 1 to 4: ";
			choice = getInt();
			switch (choice) {
			case 1:
				menu = setDPC(menu);
				break;
			case 2:
				menu = setDPCbyName(menu,dn);
				break;
			case 3:
				menu = setDPCbyID(menu, did);
				break;
			case 4:
				dealDishes(menu);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 4\n";
			}
			break;
		}
		case 5:
			menu = modifyDishes(menu);
			break;
		case 6:
			menu = deleteDishes(menu);
			break;
		case 7:
			outputMenu(menu, "menu.txt");
			ManagerMain();
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 7\n";
		}
		dealDishes(menu);
	}
	//deal with dishes

	void dealCustomer(vector<Customer> clist) {
		int cid = 0;
		string dishname;
		cout << "Choose an option:\n";
		cout << "1. Browse Customer Information\n";
		cout << "2. Search Customer Information\n";
		cout << "3. Add Customer Information\n";
		cout << "4. Modify Customer Information\n";
		cout << "5. Delete Customer Information\n";
		cout << "6. Return to deal other things\n";
		cout << "Input an Integer between 1 to 6: ";
		int choice;
		choice = getInt();
		switch (choice)
		{
		case 1:
			showCustomers(clist);
			break;
		case 2: {
			cout << "1. Search Customer by Dishes\n";
			cout << "2. Search Customer by id\n";
			cout << "3. Return\n ";
			cout << "Input an Integer between 1 to 3: ";
			choice = getInt();
			switch (choice) {
			case 1:
				searchCustomerbyDishes(clist, dishname);
				break;
			case 2:
				searchCustomerbyID(clist,cid);
				break;
			case 3:
				dealCustomer(clist);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 3\n";
			}
			break;
		}
		case 3:
			clist = addCustomer(menu,clist);
			outputMenu(menu, "menu.txt");
			break;
		case 4: {
			cout << "Choose an option:\n";
			cout << "1. Modify all Customers\n";
			cout << "2. Modify Customer according to id\n";
			cout << "3. Return \n";
			cout << "Input an Integer between 1 to 3: ";
			choice = getInt();
			switch (choice) {
			case 1:
				clist = modifyCustomer(menu,clist);
				outputMenu(menu, "menu.txt");
				break;
			case 2:
				clist = modifyCustomer(menu,clist, cid);
				outputMenu(menu, "menu.txt");
				break;
			case 3:
				dealCustomer(clist);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 3\n";
			}
			break;
		}
		
		case 5: {
			cout << "Choose an option:\n";
			cout << "1. Delete all Customers\n";
			cout << "2. Delete Customer according to id\n";
			cout << "3. Return \n";
			cout << "Input an Integer between 1 to 3: ";
			choice = getInt();
			switch (choice) {
			case 1:
				deleteCustomer(clist);
				break;
			case 2:
				deleteCustomer(clist, cid);
				break;
			case 3:
				dealCustomer(clist);
				break;
			default:
				cout << "Invalid input\n" <<
					"Please input an integer between 1 to 3\n";
			}
			break;
		}
			
		case 6:
		{
			Customer c;
			c.outputClist(clist, "customerlist.txt");
			ManagerMain();
			break;
		}
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 6\n";
		}
		dealCustomer(clist);
	}
	//deal with customers
};

