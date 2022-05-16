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