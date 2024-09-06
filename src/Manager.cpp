#include "Manager.h"
using namespace std;

vector<RawMaterial> Manager::addRawMaterial(vector<RawMaterial> rlist)
{
	RawMaterial newrm;
	cout << "Please enter the name of new raw material: " << endl;
	newrm.name = getString();
	bool same = 0;
	for (int i = 0; i < rlist.size(); i++) {
		if (newrm.name == rlist.at(i).name) {
			same = 1;
			cout << "name repeated! Please enter a different name." << endl;
			return rlist;
		}
	} // check whether the name of new raw material exists
	if (same == 0) {
		cout << "Please enter the price of new raw material: " << endl;
		newrm.price = getPosDouble();
		rlist.push_back(newrm);
		cout << "New raw material added successfully!" << endl;
		return rlist;
	}
};

vector<RawMaterial> Manager::modifyRawMaterial(vector<RawMaterial> rlist) {
	int n = rlist.size();
	if (n == 0) {
		cout << "No raw material yet" << endl;
		return rlist;
	}// check whether the list is empty
	cout << "All of " << n << "raw material need to be modified" << endl;
	for (int mn = 0; mn < n; mn++) {
		cout << "Please enter the name for raw material no." << mn + 1 << " : " << endl;
		rlist.at(mn).name = getString();
		cout << "Please enter the price for raw material no." << mn + 1 << " : " << endl;
		rlist.at(mn).price = getPosDouble();
	};
	cout << "All raw material has been modified successfully!" << endl;
	return rlist;
};

vector<RawMaterial> Manager::modifyRawMaterial(vector<RawMaterial> rlist, string r) {
	int n = rlist.size();
	int rmnotfit = 0;//used to check whether there is a matched result
	if (n == 0) {
		cout << "No raw material yet" << endl;
		return rlist;
	}// check whether the list is empty
	cout << "Please enter the name of raw material: " << endl;
	r = getString();
	for (int mn = 0; mn < n; mn++) {
		if (rlist.at(mn).name == r) {
			cout << "Raw material is found!" << endl;
			cout << "Please enter the name for raw material " << mn+1  << " : " << endl;
			rlist.at(mn).name = getString();
			cout << "Please enter the price for raw material " << mn+1 << " : " << endl;
			rlist.at(mn).price = getPosDouble();
			rmnotfit = 1;
			break;
		};
	};
	if (rmnotfit == 0) {
		cout << "No raw material found, please enter correct information" << endl;
	};
	return rlist;
};

void Manager::deleteRawMaterial(vector<RawMaterial>& rlist) {
	rlist.clear();
	cout << "All raw material has been successfully deleted!" << endl;
};

void Manager::deleteRawMaterial(vector<RawMaterial> &rlist, string r) {
	bool rmnotfit = 0; // used to check whether there is a matched result
	int n = rlist.size();
	if (n == 0) {
		cout << "No raw material yet" << endl;
		return;
	}// check whether the list is empty
	cout << "Please enter the name of raw material: " << endl;
	r = getString();
	for (int mn = 0; mn < n; mn++) {
		if (rlist.at(mn).name != r) {
			continue;
		};
		rmnotfit = 1;
		rlist.erase(rlist.begin() + mn);
		cout << "Raw material is deleted successfully!" << endl;
	};
	if (!rmnotfit) {
		cout << "No raw material found, please enter correct information" << endl;
	};
};

vector<Dishes> Manager::setDPC(vector<Dishes> menu) {
	int n = menu.size();
	if (n == 0) {
		cout << "No dish yet" << endl;
		return menu;
	}// check whether the menu is empty
	cout << "All of " << n << "Dishes' price need to be set" << endl;
	for (int i = 0; i < n; i++) {
		cout << "The current price of " << menu[i].name << " is " << menu[i].price << endl;
		cout << "The current cost of " << menu[i].name << " is " << menu[i].cost << endl;
		// show the current price and cost, to give user a better look
		cout << "Please set the new price for " << menu[i].name << " : " << endl;
		menu[i].price = getPosDouble();
		cout << "Pleas set the new cost for " << menu[i].name << " : " << endl;
		menu[i].cost = getPosDouble();
	};
	return menu;
}

vector<Dishes> Manager::setDPCbyName(vector<Dishes> menu, string n) {
	bool flag = 0;// used to check whether there is a matched result
	int ns = menu.size();
	if (ns == 0) {
		cout << "No dish yet" << endl;
		return menu;
	} // check whether the menu is empty 
	cout << "Please enter the name of dish: " << endl;
	n = getString();
	for (int i = 0; i < ns;i++) {
		if (menu[i].name == n) {
			cout << "The current price of " << menu[i].name << " is " << menu[i].price << endl;
			cout << "The current cost of " << menu[i].name << " is " << menu[i].cost << endl;
			// show the current price and cost, to give user a better look
			cout << "Please set the new price for " << menu[i].name << " : " << endl;
			menu[i].price = getPosDouble();
			cout << "Pleas set the new cost for " << menu[i].name << " : " << endl;
			menu[i].cost = getPosDouble();
			flag = 1;
		}
	};
	if (flag == 0) {
		cout << "Please enter correct name of dish!" << endl;
	}
	return menu;
}

vector<Dishes> Manager::setDPCbyID(vector<Dishes> menu, int did) {
	bool flag = 0;//used to check whether there is a matched result
	int ns = menu.size();
	if (ns == 0) {
		cout << "No dishes yet" << endl;
		return menu;
	}// check whether the menu is empty
	cout << "Please enter the id of dish: " << endl;
	did = getInt();
	for (int i = 0; i < ns;i++) {
		if (menu[i].id == did) {
			cout << "The current price of " << menu[i].name << " is " << menu[i].price << endl;
			cout << "The current cost of " << menu[i].name << " is " << menu[i].cost << endl;
			// show the current price and cost, to give user a better look
			cout << "Please set the new price for " << menu[i].name << " : " << endl;
			menu[i].price = getPosDouble();
			cout << "Pleas set the new cost for " << menu[i].name << " : " << endl;
			menu[i].cost = getPosDouble();
			flag = 1;
		}
	};
	if (flag == 0) {
		cout << "Please enter correct name of dish!" << endl;
	}
	return menu;
}

double Manager::TotalProfits(vector<Dishes> menu) {
	double sum = 0;
	for (int n = 0; n < menu.size(); n++) {
		sum += menu.at(n).numOrdered * (menu.at(n).price - menu.at(n).cost);
	};
	return sum;
};

void Manager::showCustomers(vector<Customer> clist) {
	int n = clist.size();
	if (n == 0) {
		cout << "No customers come today" << endl;
		return;
	}// check whether the list is empty
	cout << "All of " << n << " customers are shown below" << endl;
	for (int cnum = 0; cnum < n; cnum++) {
		clist.at(cnum).showCustomer();
	};
};

void Manager::searchCustomerbyDishes(vector<Customer> clist, string dishname) {
	int n = clist.size();
	if (n == 0) {
		cout << "No customers come today" << endl;
		return;
	}// check whether the list is empty
	cout << "Please enter one dish name: " << endl;
	dishname = getString();
	int resultc = 0;
	for (int nc = 0; nc < n; nc++) {
		for (int nd = 0; nd < clist.at(nc).dishesBasket.size(); nd++) {
			if (clist.at(nc).dishesBasket.at(nd).name == dishname) {
				clist.at(nc).showCustomer();
				resultc++;
				break;
			};
		};
	}
	cout << resultc << " result(s) has been found! " << endl;
};

void Manager::searchCustomerbyID(vector<Customer> clist, int id) {
	int n = clist.size();
	if (n == 0) {
		cout << "No customers come today" << endl;
		return;
	}// check whether the list is empty
	cout << "Please enter one id of customers: " << endl;
	id = getInt();
	int resultc = 0;
	for (Customer c : clist) {
		if (c.id != id) continue;
		c.showCustomer();
		resultc++;
	};
	cout << resultc << " result(s) has been found! " << endl;
}

vector<Customer> Manager::addCustomer(vector<Dishes>& menu, vector<Customer> clist) {
	Customer newc;
	cout << "Please decide the id of the new customer" << endl;
	int id = getInt();
	if (id == -1) {
		cout << "Invalid customer id" << endl;
		return clist;
	}// check whether the id already exists in the list
	newc.id = id;
	for (int i = 0; i < clist.size(); i++) {
		if (newc.id == clist.at(i).id) {
			cout << "Id repeated! Please enter a different Id." << endl;
			return clist;
		}
	}
	newc.dishesBasket = newc.addDish(menu, newc.dishesBasket);
	clist.push_back(newc);
	cout << "New customer successfully added!" << endl;
	return clist;
};

vector<Customer> Manager::modifyCustomer(vector<Dishes>& menu, vector<Customer> clist) {
	int n = clist.size();
	if (n == 0) {
		cout << "No customers come today" << endl;
		return clist;
	}// check whether the list is empty
	cout << "All of " << n << "customers need to be modified" << endl;
	for (int mn = 0; mn < n; mn++) {
		cout << "Please enter the id for customer no." << mn + 1 << " : " << endl;
		int id = getInt();
		if (id == -1) {
			cout << "Invalid customer id" << endl;
			return clist;
		}
		for (int i = 0; i < clist.size(); i++) {
			if (id == clist.at(i).id) {
				cout << "Id repeated! Please enter a different Id." << endl;
				return clist;
			}
		}
		clist.at(mn).id = id;
		clist.at(mn).dishesBasket = clist.at(mn).addDish(menu, clist.at(mn).dishesBasket);
	}
	return clist;
};

vector<Customer> Manager::modifyCustomer(vector<Dishes>& menu, vector<Customer> clist, int id) {
	int n = clist.size();
	bool cnotfit = 0; // used to check whether there is a matched result in the list
	if (n == 0) {
		cout << "No customers come today" << endl;
		return clist;
	}// check whether the list is empty
	cout << "Please enter the id of customer: " << endl;
	id = getInt();
	for (int mn = 0; mn < n; mn++) {
		if (clist.at(mn).id == id) {
			clist.at(mn).dishesBasket = clist.at(mn).addDish(menu, clist.at(mn).dishesBasket);
			cnotfit = 1;
			break;
		};
	};
	if (cnotfit == 0) {
		cout << "No customer found, please enter correct information" << endl;
	};
	return clist;
}

void Manager::deleteCustomer(vector<Customer>& clist) {
	clist.clear();
	cout << "All customers have been successfully deleted!" << endl;
}

void Manager::deleteCustomer(vector<Customer>& clist, int i) {
	int n = clist.size();
	bool cnotfit = 0; // used to check whether there is a matched result in the list
	if (n == 0) {
		cout << "No customers come today" << endl;
		return;
	}// check whether the list is empty
	cout << "Please enter the id of customer: " << endl;
	i = getInt();
	for (unsigned int mn = 0; mn < n; mn++) {
		if (clist.at(mn).id != i) {
			continue;
		};
		cnotfit = 1;
		clist.erase(clist.begin() + mn);
		cout << "Customer is deleted successfully!" << endl;
	};
	if (!cnotfit) {
		cout << "No customer found, please enter correct information" << endl;
	};
}

void Manager::ManagerMain() {
	rlist = loadRlist("rawmaterial.txt");
	menu = loadMenu("menu.txt");
	Customer c;
	clist = c.loadClist("customerlist.txt");
	cout << "\n" << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
	cout << "*\t" << "Role: A Manager in the restaurant" << setw(16) << "*" << endl;
	cout << "*\t" << "Choose an option: " << setw(31) << "*" << endl;
	cout << "*\t" << "1. Deal with Raw Material" << setw(24) << "*" << endl;
	cout << "*\t" << "2. Deal with Menu" << setw(32) << "*" << endl;
	cout << "*\t" << "3. Deal with Customer Information" << setw(16) << "*" << endl;
	cout << "*\t" << "4. Show current profits in total" << setw(17) << "*" << endl;
	cout << "*\t" << "5. Exit" << setw(42) << "*" << endl;;
	cout << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
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

void Manager::dealRawMaterial(vector<RawMaterial> rlist) {
	cout << "\n" << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
	cout << "*\t" << "Choose an option: " << setw(31) << "*" << endl;
	cout << "*\t" << "1. Browse RawMaterial" << setw(28) << "*" << endl;;
	cout << "*\t" << "2. Search RawMaterial" << setw(28) << "*" << endl;
	cout << "*\t" << "3. Add RawMaterial" << setw(31) << "*" << endl;
	cout << "*\t" << "4. Modify RawMaterial" << setw(28) << "*" << endl;
	cout << "*\t" << "5. Delete RawMaterial" << setw(28) << "*" << endl;
	cout << "*\t" << "6. Return to deal other things" << setw(19) << "*" << endl;
	cout << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
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

void Manager::dealDishes(vector<Dishes> menu) {
	cout << "\n" << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
	cout << "*\t" << "Choose an option:" << setw(32) << "*" << endl;
	cout << "*\t" << "1. Browse Menu (according to popularity)" << setw(9) << "*" << endl;
	cout << "*\t" << "2. Search Dish" << setw(35) << "*" << endl;
	cout << "*\t" << "3. Add Dish" << setw(38) << "*" << endl;
	cout << "*\t" << "4. Modify Dish price and cost" << setw(20) << "*" << endl;
	cout << "*\t" << "5. Modify Menu" << setw(35) << "*" << endl;
	cout << "*\t" << "6. Delete Dish" << setw(35) << "*" << endl;
	cout << "*\t" << "7. Return to deal other things" << setw(19) << "*" << endl;
	cout << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
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
			menu = setDPCbyName(menu, dn);
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

void Manager::dealCustomer(vector<Customer> clist) {
	int cid = 0;
	string dishname;
	cout << "\n" << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
	cout << "*\t" << "Choose an option:" << setw(32) << "*" << endl;
	cout << "*\t" << "1. Browse Customer Information" << setw(19) << "*" << endl;
	cout << "*\t" << "2. Search Customer Information" << setw(19) << "*" << endl;
	cout << "*\t" << "3. Add Customer Information" << setw(22) << "*" << endl;
	cout << "*\t" << "4. Modify Customer Information" << setw(19) << "*" << endl;
	cout << "*\t" << "5. Delete Customer Information" << setw(19) << "*" << endl;
	cout << "*\t" << "6. Return to deal other things" << setw(19) << "*" << endl;
	cout << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
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
			searchCustomerbyID(clist, cid);
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
		clist = addCustomer(menu, clist);
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
			clist = modifyCustomer(menu, clist);
			outputMenu(menu, "menu.txt");
			break;
		case 2:
			clist = modifyCustomer(menu, clist, cid);
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