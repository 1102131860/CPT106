#include "Customer.h"
#include<iostream>
using namespace std;
void Customer::outputClist(vector<Customer> clist, string address) {
	fstream fout(address, ios::out);
	fout << "Customerid\t" << "DishesBasket\t" << "TotalPrice\t" << "Profits\n";
	for (Customer c : clist) {
		if (!c.dishesBasket.empty()) {
			fout << c.id << '\t';
			for (int i = 0; i < (c.dishesBasket.size() - 1); i++) {
				fout << c.dishesBasket[i].id << "." << c.dishesBasket[i].name << ",";
			}
			fout << c.dishesBasket.at(c.dishesBasket.size() - 1).id << "."
				<< c.dishesBasket.at(c.dishesBasket.size() - 1).name << '\t'
				<< c.totalPrice << '\t' << c.profits << endl;
		}
	}
}

vector<Customer> Customer::loadClist(string address) {
	vector<Customer> clist;
	Customer newc;
	string str;

	fstream fin(address, ios::in);
	if (!fin.is_open()) return clist;
	while (fin.eof() == 0) {
		getline(fin, str);
		if (str.empty()) break;
		if (!isdigit(str.at(0))) continue;
		vector<string> linesplit = stringSplit(str, '\t');
		//deal with customer's dishesbasket
		if (linesplit.size() != 4) break;
		vector<string> dishesName = stringSplit(linesplit.at(1), ',');
		vector<Dishes> dishBasket;
		try {
			for (string s : dishesName) {
				vector<string> dishestuple = stringSplit(s, '.');
				if (dishestuple.size() != 2) break;
				Dishes newd = { dishestuple.at(1),stoi(dishestuple.at(0),0,10) };
				dishBasket.push_back(newd);
			}
			newc.id = stoi(linesplit.at(0), 0, 10);
			newc.dishesBasket = dishBasket;
			newc.totalPrice = stod(linesplit.at(2), 0);
			newc.profits = stod(linesplit.at(3), 0);
			clist.push_back(newc);
		}
		catch (invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			return clist;
		}
	}
	return clist;
}
// This function is to order dish.
/* add dish
	first check whether the dish is in the menu
	then check whether the dish have been ordered
	order number of dish plus 1
	last add the dish to dish Basket£¨order£©
	 */
vector<Dishes> Customer::addDish(vector<Dishes>& menu, vector<Dishes> dishesBasket) {
	int check = 1;
	cout << "Choose an option: " << endl;
	cout << "1. add dishes by ID" << endl;
	cout << "2. add dishes by Name" << endl;
	cout << "3. exit" << endl;
	
		int choice = getInt();
		int a = 0;
		string b = "";
		switch (choice)
		{
		case 1:
			cout << "Please input id: "<<endl;
			a = getInt();
			addDishByID(menu, dishesBasket, a);
			break;
		case 2:
			cout << "Please input name: "<<endl;
			getline(cin, b);
			addDIshByName(menu, dishesBasket, b);
			break;
		case3:
			return dishesBasket;
			break;
		default:
			cout << "Invalid input\n" <<"Please input an integer between 1 to 3\n";
		}
		return dishesBasket;
	
};

	void Customer::addDishByID(vector<Dishes>& menu, vector<Dishes>&dishesBasket, int did){
		for (unsigned int i = 0; i < menu.size(); i++) {
			if (did != menu[i].id)  continue;
			if (findDishesByID(dishesBasket, did)) {
				cout << "You have ordered this dish." << endl;
			}
			else {
				totalPrice += menu[i].price;
				profits += menu[i].price - menu[i].cost;
				menu[i].numOrdered += 1;//change the number ordered of the dish
				dishesBasket.push_back(menu[i]);
				break;
			};
		}
		cout << getDishesInBasket(dishesBasket) << endl;//print order the dishes.Give the feedback that order works 
		if (findDishesByID(menu, did) == 0) {
			cout << "You inputted a invalid id." << endl;
		}
	};


void Customer::addDIshByName(vector<Dishes>& menu, vector<Dishes> &dishesBasket, string Name){
	for (unsigned int i = 0; i < menu.size(); i++) {
		if (Name != menu[i].name)  continue;
		if (findDishesByName(dishesBasket, Name)) {
			cout << "You have ordered this dish." << endl;
		}
		else { 
			totalPrice += menu[i].price;
			profits += menu[i].price - menu[i].cost;
			menu[i].numOrdered += 1;//change the number ordered of the dish
			dishesBasket.push_back(menu[i]);
			break;
		};
	}
	if (findDishesByName(menu, Name)==0) {
		cout << "You inputted a invalid dish name." << endl;
	}
	cout << getDishesInBasket(dishesBasket) << endl;//print order the dishes.Give the feedback that order works
};
//delete dish in the order before checkout
vector<Dishes>Customer::deleteDish(vector<Dishes>& menu, vector<Dishes> dishesBasket) {
	int check = 1;
	cout << "Choose an option: " << endl;
	cout << "1. delete dishes by ID" << endl;
	cout << "2. delete dishes by Name" << endl;
	cout << "3. exit" << endl;

	int choice = getInt();
	int a = 0;
	string b = "";
	switch (choice)
	{
	case 1:
		cout << "Please input id: " << endl;
		a = getInt();
		deleteDishByID(menu,dishesBasket, a);
		break;
	case 2:
		cout << "Please input name: " << endl;
		getline(cin, b);
		deleteDishByName(menu,dishesBasket, b);
		break;
	case3:
		return dishesBasket;
	default:
		cout << "Invalid input\n" <<
			"Please input an integer between 1 to 3\n";
	}return dishesBasket;

};

void Customer::deleteDishByID(vector<Dishes>& menu,vector<Dishes>& dishesBasket, int did) {

	for (unsigned int i = 0; i < dishesBasket.size(); i++) {
		if (dishesBasket[i].id != did) continue;
		//find the dish to delete
		totalPrice -= dishesBasket[i].price;
		profits -= dishesBasket[i].price - dishesBasket[i].cost;
		for (int j = 0; j < menu.size(); j++) {
			if (menu[j].id == did) {
				menu[j].numOrdered -= 1;//change the number ordered of the dish
			}
		}
		dishesBasket.erase(dishesBasket.begin() + i);
		cout << "the dish is deleted" << endl;
		cout << getDishesInBasket(dishesBasket) << endl; 
		break;
	}if (findDishesByID(dishesBasket,did)) {
		cout << "You inputted a incorrect id." << endl;
		cout << getDishesInBasket(dishesBasket) << endl; 
	}
};
void Customer::deleteDishByName(vector<Dishes>& menu,vector<Dishes>& dishesBasket, string name){
	if (dishesBasket.size() == 0) { cout << "Please order a dish first." << endl; }//check whether customer ordered a dish or not. 
	for (unsigned int i = 0; i < dishesBasket.size(); i++) {
		if (dishesBasket[i].name != name) continue;
        //find the dish to delete
		totalPrice -= dishesBasket[i].price;
		profits -= dishesBasket[i].price - dishesBasket[i].cost;
		for (int j = 0; j < menu.size(); j++) {
			if (menu[j].name == name) {
				menu[j].numOrdered -= 1;//change the number ordered of the dish
			}
		}
		dishesBasket.erase(dishesBasket.begin() + i);
		cout << "the dish is deleted" << endl;
	    cout << getDishesInBasket(dishesBasket) << endl; 
		break;
	}if (findDishesByName(dishesBasket,name)) {
		cout << "You inputted a incorrect name." << endl;
		 cout << getDishesInBasket(dishesBasket) << endl; 
	}
};

//outprint id and price
void Customer::check_out(vector<Dishes> dishesBasket, vector<Dishes>menu){
	cout << "Guest id:  " << id << endl;
	showDishesBasket(dishesBasket);
	cout << "Please pay " << totalPrice << endl;
};
//print the ordered dish
void Customer::showDishesBasket(vector<Dishes> dishesBasket) {
	if (dishesBasket.size() == 0) { cout << "Please order a dish first." << endl; }
	else {
		double total = 0.0;
		for (unsigned int i = 0; i < dishesBasket.size(); i++) {
			dishesBasket[i].showWOTcost();
			total += dishesBasket[i].price;
		}
		cout << "The total price is: " << total << endl;
	}
};
//store the information of customer
vector<Customer> Customer::addCustomer(Customer& c){
	clist.push_back(c);
	return clist;
};
//show customer's dishbasket£¬manager use thatdifferent from customer's show DishesBasket
string Customer::getDishesInBasket(vector<Dishes> d) {
	string dishName = "Ordered dishes: ";
	if (d.empty()) return "No dish in dishesBasket";
	for (int i = 0; i < d.size() - 1; i++) {
		dishName += (to_string(d[i].id) + "." + d[i].name + ", ");
	}
	dishName += to_string(d[d.size() - 1].id) + "." + d[d.size() - 1].name;
	return dishName;
}
//Show customer itself£¬show mananger;
void Customer::showCustomer() {
	string dishesname = getDishesInBasket(dishesBasket);
	string dishes = dishesname.substr(16);
	cout << id << "\tOrdered dishes: " << setw(65) << dishes
		<< "\tTotal price: " << setw(7) << totalPrice << "\tProfits: "
		<< setw(7) << profits << endl;
}
//Interface with main function
void Customer::CustomerMain(Customer& c) {
	menu = loadMenu("menu.txt");
	clist = loadClist("customerlist.txt");
	id = clist.size() + 1;
	cout << "\n" << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
	cout << "*\t" << "Role: A customer in the restaurant" << setw(15) << "*" << endl;
	cout << "*\t" << "Choose an option: " << setw(31) << "*" << endl;
	cout << "*\t" << "1. Browse the Menu" << setw(31) << "*" << endl;
	cout << "*\t" << "2. Search dishes" << setw(33) << "*" << endl;
	cout << "*\t" << "3. Add dish into DishesBasket" << setw(20) << "*" << endl;
	cout << "*\t" << "4. Delete dish from DishesBasket" << setw(17) << "*" << endl;
	cout << "*\t" << "5. Browse the DishesBasket" << setw(23) << "*" << endl;
	cout << "*\t" << "6. Check-out" << setw(37) << "*" << endl;
	cout << setw(57) << setfill('*') << "*" << setfill(' ') << endl;
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
		dishesBasket = addDish(menu, dishesBasket);
		outputMenu(menu, "menu.txt");
		break;
	case 4:
		dishesBasket = deleteDish(menu, dishesBasket);
		outputMenu(menu, "menu.txt");
		break;
	case 5:
		showDishesBasket(dishesBasket);
		break;
	case 6:
		check_out(dishesBasket, menu);
		clist = addCustomer(c);
		outputClist(clist, "customerlist.txt");
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