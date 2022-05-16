#include "PerInRes.h"
vector<Dishes> PerInRes::sort(vector<Dishes> t) {      //用之前先t.copy()创造一个新的vector<Dishes>，再对新的vector<Dishes>用sort
	Dishes d;
	for (int i = 0; i < t.size(); i++) {
		for (int j = i + 1; j < t.size(); j++) {
			if (t[j] > t[i]) {
				d = t[j];
				t[j] = t[i];
				t[i] = d;
			}
		}
	}
	return t;
}

int PerInRes::getInt() {
	string input = "";
	getline(cin, input);
	if (input.empty()) return -1;
	//判断input里是否包含非数字的char
	//如果出现12e或者e12就不转换了
	bool flag = 1;
	for (char i : input) {
		if (isdigit(i)) continue;
		flag = 0;
		break;
	}
	int num = -1;
	if (flag) num = stoi(input, 0, 10);
	return num;
}

double PerInRes::getPosDouble() {
	string input = "";
	getline(cin, input);
	bool flag = 1;
	int numOfDot = 0;
	//如果出现1.2e或者1.1.2e就不转换了
	for (char i : input) {
		if (isdigit(i)) continue;
		if (i == '.' && numOfDot == 0) {
			numOfDot++;
			continue;
		}
		flag = 0;
		break;
	}
	double dou = -1;
	try {
		if (flag) dou = stod(input, 0);
	}
	catch (invalid_argument &e) {
		return dou;
	}
	return dou;
}

string PerInRes::getString() {
	string str = "";
	getline(cin, str);
	return str;
}

vector<string> PerInRes::stringSplit(string str, char cr) {
	string collector = "";
	vector<string> strVector;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == cr) {
			strVector.push_back(collector);
			collector = "";
			continue;
		}
		collector += str[i];
		if (i == str.size() - 1) strVector.push_back(collector);
	}
	return strVector;
}

bool PerInRes::findDishesByID(vector<Dishes> t, int did) {
	for (Dishes d : t) {
		if (d.id == did) return 1;
	}
	return 0;
}

bool PerInRes::findDishesByName(vector<Dishes> t, string name) {
	for (Dishes d : t) {
		if (d.name == name) return 1;
	}
	return 0;
}

void PerInRes::showMenu(vector<Dishes> menu) {
	cout << "Choose an option:\n";
	cout << "1. Show menu in ascending id sequence\n" ;
	cout << "2. Show menu accordding to populartion\n";

	cout << "Input an integer between 1 to 2: ";
	int choice = getInt();
	switch (choice)
	{
	case 1:
		showMenuNomally(menu);
		break;
	case 2:
		showPopularDishes(menu);
		break;
	default:
		cout << "Invalid input\n" <<
			"Please input an integer between 1 to 2\n";
	}
}

void PerInRes::showMenuNomally(vector<Dishes> t) {
	for (Dishes d : t) {
		d.showWOTcost();
	}
}

void PerInRes::showPopularDishes(vector<Dishes> t) {
	showMenuNomally(sort(t));
}

void PerInRes::searchDishesByID(vector<Dishes> t, int id) {
	for (Dishes d : t) {
		if (d.id != id) continue;
		d.showWOTcost();
	}
	if (!findDishesByID(t, id)) cout << "No dish in menu has the same id\n";
}

void PerInRes::searchDishesByName(vector<Dishes> t, string name) {
	for (Dishes d : t) {
		if (d.name != name) continue;
		d.showWOTcost();
	}
	if (!findDishesByName(t,name)) cout << "No dish in menu has same name \n";
}

void PerInRes::searchDishesByRaw(vector<Dishes> t, string RawMaterialName) {
	bool flag = 0;
	for (Dishes d : t) {
		for (RawMaterial r : d.rawVector) {
			if (r.name != RawMaterialName) continue;
			d.showWOTcost();
			flag = 1;
		}
	}
	if (flag == 0) cout << "No dish in menu contain the rawmaterial you input\n";
}

void PerInRes::searchDishesByPrice(vector<Dishes> t, double price) {
	bool flag = 0;
	for (Dishes d : t) {
		if (d.price != price) continue;
		d.showWOTcost();
		flag = 1;
	}
	if (flag == 0) cout << "No dish in menu has the same price\n";
}

void PerInRes::searchDishes(vector<Dishes> t) {
	cout << "Search Dishes By \n";
	cout << "1. By id\n";
	cout << "2. By Name\n";
	cout << "3. By Raw Material\n";
	cout << "4. By Price\n";

	cout << "Input an integer between 1 to 4: ";
	int choice = getInt();
	switch (choice)
	{
	case 1: 
	{
		cout << "Input the dish's id which you wanna search: ";
		int id = getInt();
		searchDishesByID(t, id);
		break;
	}
	case 2:
	{
		cout << "Input the dish's name which you wanna search: ";
		string name = getString();
		searchDishesByName(t, name);
		break;
	}
	case 3:
	{
		cout << "Input the raw material's name so that you can see"
			<< " all the dishes containing the raw material :";
		string rname = getString();
		searchDishesByRaw(t, rname);
		break;
	}
	case 4:
	{
		cout << "Input price so that you can see"
			<< " all the dishes with the same price:";
		double price = getPosDouble();
		searchDishesByPrice(t, price);
		break;
	}
	default:
		cout << "Invalid input\n" <<
			"Please input an integer between 1 to 4\n";
	}
}

vector<Dishes> PerInRes::loadMenu(string menuaddress) {
	vector<Dishes> menu;
	string str;
	Dishes d;

	fstream fin(menuaddress, ios::in);
	if (!fin.is_open()) return menu;
	while (fin.eof() == 0) {
		getline(fin, str);
		if (str.empty()) break;
		if (!isdigit(str.at(0))) continue;
		vector<string> linesplit = stringSplit(str, '\t');
		if (linesplit.size() != 6) break;
		//处理dishes的rawVector
		string rawInfor = linesplit.at(4);
		vector<string> rawsplit = stringSplit(rawInfor, ',');
		vector<RawMaterial> rawVector;
		for (string s : rawsplit) {
			RawMaterial newRaw = { s };
			rawVector.push_back(newRaw);
		}
		try {
			d = { linesplit.at(1) ,stoi(linesplit.at(0),0,10),stod(linesplit.at(2),0),//id,name,price
			stod(linesplit.at(3),0),rawVector,stoi(linesplit.at(5),0,10)};//cost,rawMaterials,numordered
			menu.push_back(d);
			cout << "Dish " << linesplit.at(1) << " has been successfully loaded in\n";
		}
		catch (invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			return menu;
		}
	}
	return menu;
}

vector<RawMaterial> PerInRes::loadRlist(string address) {
	vector<RawMaterial> rlist;
	string str;
	RawMaterial newRaw;

	fstream fin(address, ios::in);
	if (!fin.is_open()) return rlist;
	while (fin.eof() == 0) {
		getline(fin, str);
		if (str == "RawMaterialName\tPrice") continue;
		try {
			vector<string> linesplit = stringSplit(str, '\t');
			if (linesplit.size() != 2) break;
			newRaw = { linesplit.at(0),stod(linesplit.at(1),0)};
			rlist.push_back(newRaw);
			cout << "Raw material " << newRaw.name << " has been successfully loaded in\n";
		}
		catch (invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			return rlist;
		}
	}
	return rlist;
}

//放在customer或者manager里

//vector<Customer> Customer::loadClist(string address) {
//	vector<Customer> clist;
//	Customer newc;
//	string str;
//
//	fstream fin(address, ios::in);
//	if (!fin.is_open()) return clist;
//	while (fin.eof() == 0) {
//		getline(fin, str);
//		if (str.empty()) break;
//		if (!isdigit(str.at(0))) continue;
//		vector<string> linesplit = stringSplit(str, '\t');
//		//处理customer的dishesbasket
//		if (linesplit.size() != 4) break;
//		vector<string> dishesName = stringSplit(linesplit.at(1), ',');
//		vector<Dishes> dishBasket;
//		try {
//			for (string s : dishesName) {
//				vector<string> dishestuple = stringSplit(s, '.');
//				if (dishestuple.size() != 2) break;
//				Dishes newd = { dishestuple.at(1),stoi(dishestuple.at(0),0,10) };
//				dishBasket.push_back(newd);
//			}
//			newc.id = stoi(linesplit.at(0), 0, 10);
//			newc.dishesBasket = dishBasket;
//			newc.totalPrice = stod(linesplit.at(2), 0);
//			newc.profits = stod(linesplit.at(3), 0);
//			clist.push_back(newc);
//			cout << "Customer " << linesplit.at(0) << " has been successfully loaded in\n";
//		}
//		catch (invalid_argument& e) {
//			cout << "Error: " << e.what() << endl;
//			return clist;
//		}
//	}
//	return clist;
//}

void PerInRes::outputRlist(vector<RawMaterial> rlist, string address) {
	fstream fout(address, ios::out);
	fout << "RawMaterialName\t" << "Price\n";
	for (RawMaterial r : rlist) {
		fout << r.name << '\t' << r.price << endl;
	}
	cout << "Raw Material information has been successfully loaded out\n";
}

void PerInRes::outputMenu(vector<Dishes> menu, string address) {
	fstream fout(address, ios::out);
	fout << "Dishesid" << "\tName" << "\tPrice" << "\tCost" << "\tRawMaterialName" << "\tNumOrdered\n";
	for (Dishes d : menu) {
		string rawmaterialname = "";
		for (int i = 0; i < d.rawVector.size() - 1; i++) {
			rawmaterialname += (d.rawVector[i].name + ",");
		}
		rawmaterialname += d.rawVector.at(d.rawVector.size() - 1).name;
		fout << d.id << '\t' << d.name << '\t' << d.price << '\t'	//id,name,price
			<< d.cost << '\t' << rawmaterialname << '\t' << d.numOrdered << endl;//cost,rawmeterialname,numordered
	}
	cout << "Menu has been successfully load out\n";
}

//放在customer或者manager里

//void Customer::outputClist(vector<Customer> clist, string address) {
//	fstream fout(address, ios::out);
//	fout << "Customerid\t" << "DishesBasket\t" << "TotalPrice\t" << "Profits\n";
//	for (Customer c : clist) {
//		if (!c.dishesBasket.empty()) {
//			fout << c.id << '\t';
//			for (int i = 0; i < (c.dishesBasket.size() - 1); i++) {
//				fout << c.dishesBasket[i].id << "." << c.dishesBasket[i].name << ",";
//			}
//			fout << c.dishesBasket.at(c.dishesBasket.size() - 1).id << "."
//				<< c.dishesBasket.at(c.dishesBasket.size() - 1).name << '\t'
//				<< c.totalPrice << '\t' << c.profits << endl;
//		}
//	}
//	cout << "Customer information has been successfully load out\n";
//}

//void PerInRes::PerInResMain() {
//	//menu = readfile(menu);读取文件
//	//也可以在下面增加一个case 0;menu = readfile(menu);
//	loadMenu("menu.txt");
//
//	cout << "\nRole: A person in the restaurant" << endl;
//	cout << "Choose an option: " << endl;
//	cout << "1. Browse the Menu" << endl;
//	cout << "2. Search dishes" << endl;
//	cout << "3. Exits" << endl;
//
//	cout << "Input 1 or 2: ";
//	int choice = getInt();
//	switch (choice)
//	{
//	case 1:
//		showMenu(menu);
//		break;
//	case 2:
//		searchDishes(menu);
//		break;
//	case 3:
//		exit(0);
//		break;
//	default:
//		cout << "Invalid input" << endl;
//	}
//	PerInResMain();
//}

