#include "PerInRes.h"
//sort dishes according to popularity
//dishes > operator overloading
vector<Dishes> PerInRes::sort(vector<Dishes> t) {
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
//return positive integer, return -1 if invalid input
int PerInRes::getInt() {
	string input = "";
	getline(cin, input);
	if (input.empty()) return -1;
	bool flag = 1;
	for (char i : input) {
		if (isdigit(i)) continue;
		flag = 0;
		break;
	}
	int num = -1;
	try {
		if (flag) num = stoi(input, 0, 10);
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
		return num;
	}
	return num;
}
//return positive double, return -1 if invalid input
double PerInRes::getPosDouble() {
	string input = "";
	getline(cin, input);
	bool flag = 1;
	int numOfDot = 0;
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
//return string in a line
string PerInRes::getString() {
	string str = "";
	getline(cin, str);
	return str;
}
//according to specific character, split a string, return output in vector<string>
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
//check whether a specific dish with specific id exists in a vector
bool PerInRes::findDishesByID(vector<Dishes> t, int did) {
	for (Dishes d : t) {
		if (d.id == did) return 1;
	}
	return 0;
}
//check whether a specific dish with specific name exists in a vector
bool PerInRes::findDishesByName(vector<Dishes> t, string name) {
	for (Dishes d : t) {
		if (d.name == name) return 1;
	}
	return 0;
}
//show menu
void PerInRes::showMenu(vector<Dishes> menu) {
	cout << "Choose an option:\n";
	cout << "1. Show menu normally\n" ;
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
//show menu normally
void PerInRes::showMenuNomally(vector<Dishes> t) {
	for (Dishes d : t) {
		d.showWOTcost();
	}
}
//show menu according to dishes popularity
void PerInRes::showPopularDishes(vector<Dishes> t) {
	showMenuNomally(sort(t));
}
//search dish by ID
void PerInRes::searchDishesByID(vector<Dishes> t, int id) {
	for (Dishes d : t) {
		if (d.id != id) continue;
		d.showWOTcost();
	}
	if (!findDishesByID(t, id)) cout << "No dish in menu has the same id\n";
}
//search dish by name
void PerInRes::searchDishesByName(vector<Dishes> t, string name) {
	for (Dishes d : t) {
		if (d.name != name) continue;
		d.showWOTcost();
	}
	if (!findDishesByName(t,name)) cout << "No dish in menu has same name \n";
}
//show all dishes containing specific raw materials
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
//show all dishes with specific price
void PerInRes::searchDishesByPrice(vector<Dishes> t, double price) {
	bool flag = 0;
	for (Dishes d : t) {
		if (d.price != price) continue;
		d.showWOTcost();
		flag = 1;
	}
	if (flag == 0) cout << "No dish in menu has the same price\n";
}
//search dishes
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
//read information about menu from file
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
		}
		catch (invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			return menu;
		}
	}
	return menu;
}
//read information about raw materials from file
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
		}
		catch (invalid_argument& e) {
			cout << "Error: " << e.what() << endl;
			return rlist;
		}
	}
	return rlist;
}
//output information about raw materials into file
void PerInRes::outputRlist(vector<RawMaterial> rlist, string address) {
	fstream fout(address, ios::out);
	fout << "RawMaterialName\t" << "Price\n";
	for (RawMaterial r : rlist) {
		fout << r.name << '\t' << r.price << endl;
	}
}
//output information about menu into file
void PerInRes::outputMenu(vector<Dishes> menu, string address) {
	fstream fout(address, ios::out);
	fout << "Dishesid" << "\tName" << "\tPrice" << "\tCost" << "\tRawMaterialName" << "\tNumOrdered\n";
	for (Dishes d : menu) {
		string rawmaterialname = "";
		for (int i = 0; i < d.rawVector.size() - 1; i++) {
			rawmaterialname += (d.rawVector[i].name + ",");
		}
		rawmaterialname += d.rawVector.at(d.rawVector.size() - 1).name;
		fout << d.id << '\t' << d.name << '\t' << d.price << '\t'
			<< d.cost << '\t' << rawmaterialname << '\t' << d.numOrdered << endl;
	}
}

