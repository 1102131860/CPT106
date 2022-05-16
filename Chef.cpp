#include "Chef.h"
using namespace std;

void Chef::browseRawMateroal(vector<RawMaterial> list) {
	bool j = 0;
	for (int i = 0; i < list.size(); i++) {
		list[i].show();
		j = 1;
	}
	if (!j) cout << "No rawmaterial!" << endl;
}



void Chef::searchRawMaterial(vector<RawMaterial> list) {
	string rawmaterial;
	cout << "Please input the raw material you are searching:" << endl;
	rawmaterial = getString();
	searchRawMaterial(list, rawmaterial);
}

void Chef::searchRawMaterial(vector<RawMaterial> list, string rname) {
	bool flag = 0;
	for (RawMaterial r : list) {
		if (r.name == rname) {
			r.show();
			flag = 1;
		}
	}
	if(!flag) cout << "We do not find the raw material you want." << endl;
}



void Chef::searchDishes(vector<Dishes> t) {
	int k = 0;
	int id;
	string name;
	string rawmaterial;
	double price;

	cout << "1.search dishes by name\n" << "2.search dishes by raw\n"
		<< "3.seach dishes by price\n" << "4.search dishes by id" << endl;
	cout << "Please input an integer between 1 to 4: ";
	k = getInt();
	if (k == 1) {
		cout << "Please input the name you are looking for:" << endl;
		name = getString();
		searchDishesByName(t, name);
	}
	if (k == 2) {
		cout << "Please input the raw material you are looking for:" << endl;
		rawmaterial = getString();
		searchDishesByRaw(t, rawmaterial);
	}
	if (k == 3) {
		cout << "Please input the price you are looking for:" << endl;
		price = getPosDouble();
		searchDishesByPrice(t, price);
	}
	if (k == 4) {
		cout << "Please input the id you are looking for:" << endl;
		id = getInt();
		searchDishesByID(t, id);
	}if (k != 1 && k != 2 && k != 3 && k != 4) {
		cout << "Input an integer between 1 to 4!" << endl;
	}
}
void  Chef::searchDishesByName(vector<Dishes> t, string name) {
	bool flag = 0;
	for (Dishes r : t) {  //r belongs to t
		if (name == r.name) {
			r.showAll();
			flag = 1;
		}
	}
	if (!flag) cout << "No such dish named " << name << " in menu!" << endl;
}
void  Chef::searchDishesByRaw(vector<Dishes> t, string RawMaterialName) {
	bool flag = 0;
	for (Dishes r : t) {  //r belongs to t
		for(RawMaterial  a : r.rawVector) {
			if(a.name==RawMaterialName) {
				r.showAll();
				flag = 1;
			}
		}
	}
	if (!flag) cout << "No dish in menu contains raw material " << RawMaterialName << endl;
}
void  Chef::searchDishesByPrice(vector<Dishes> t, double price) {
	bool flag = 0;
	for (Dishes r : t) {  //r belongs to t
		if (price == r.price) {
			r.showAll();
			flag = 1;
		}
	}
	if (!flag) cout << "No price of dish in menu is " << price << endl;
}

void  Chef::searchDishesByID(vector<Dishes> t, int did) {
	bool flag = 0;
	for(Dishes r:t){  //r belongs to t
		if (did == r.id) {
			r.showAll();
			flag = 1;
	    }
	}
	if (!flag) cout << "No such dish in menu whose id is " << did << endl;
}

void Chef::showMenu(vector<Dishes> t){
	int i;
	if (t.empty()) {
		cout << "No dish in menu!" << endl;
		return;
	}
	cout << "1.Show normal menu\n" << "2.Show popular menu\n"  << "Please input 1 or 2" << endl;
	i = getInt();
	switch (i) {
	case 1:
		for (Dishes r : t) {
			r.showAll();
		}
		break;
	case 2: 
		showPopularDishes(t);
		break;
	default:
		cout << "Please input a valid integer." << endl;
		break;
	}
	
}

void Chef::showPopularDishes(vector<Dishes> t) {
	t = sort(t);
	for (Dishes r : t) {
		r.showAll();
	}
}

vector<Dishes> Chef::addDishes(vector<Dishes> menu) {
	Dishes N;
	string name;
	string Rawmaterial;
	int id;
	vector<RawMaterial> nam;

	cout << "Please input the dishes name:" << endl;
	name = getString();
	cout << "Please input the dishes ID:" << endl;
	id = getInt();
	if (id == -1) {
		cout << "Invalid dish id" << endl;
		return menu;
	}
	if (findDishesByName(menu, name) == 1 || findDishesByID(menu, id) == 1) {
		cout << "The dishes' name or ID has already existed in the menu." << endl;
		return menu;
	}
	
	cout << "The following procedure is used to add the rawmaterial:" << endl;
	cout << "Press 'stop' when adding rawmaterial to stop adding the rawmaterial:" << endl;
	while (true) {
		cout << "Please input the raw material of the dishes:" << endl;
		Rawmaterial = getString();
		if (Rawmaterial == "stop")
		{
			break;
		}
		RawMaterial t = {Rawmaterial,0};
		nam.push_back(t);
	}

	N = { name, id, 0, 0, nam, 0 };
	menu.push_back(N);
	return menu;
}


vector<Dishes> Chef::modifyDishes(vector<Dishes> menu) {
	bool flag = 0;
	int id;
	string name;
	int i = 0;
	string Rawmaterial;
	RawMaterial p;

	cout << "Please input the name of dish  you want to change:" << endl;
	name = getString();
	cout << "Please input the id of dish you want to change:" << endl;
	id = getInt();
	//judge wheather the user input id or name exsits in menu
	for (int j = 0; j < menu.size(); j++) {
		if (menu[j].name==name ||menu[j].id == id) {
			i = j;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "Sorry, the id or name does not exist in the menu." << endl;
		return menu;
	}

	//start to modify found dish
	cout << "input the new name:" << endl;
	name=getString();
	//no repeated dish name
	for (int j = 0; j < menu.size(); j++) {
		if (j == i || name != menu[j].name) continue;
		cout << "This new name has already existed in the menu." << endl;
		return menu;
	}
	menu[i].name = name;

	cout << "Please input the new id:" << endl;
	id=getInt();
	//no repeated dish id
	for (int j = 0; j < menu.size(); j++) {
		if (j == i || id != menu[j].id) continue;
		cout << "This new id has already existed in the menu." << endl;
		return menu;
	}
	menu[i].id = id;

	menu[i].rawVector.clear();
	cout << "The following procedure is used to modify the rawmaterial" << endl;
	cout << "Press 'stop' when adding rawmaterialto stop adding the rawmaterial" << endl;
	while(true) {
		cout << "Input the raw material of the dishes:" << endl;
		Rawmaterial = getString();
		if (Rawmaterial == "stop") break;
		p.name = Rawmaterial;
		menu[i].rawVector.push_back(p);
	}
	return menu;
}


vector<Dishes> Chef::deleteDishes(vector<Dishes> menu) {
	int t;
	int id;
	string name;

	cout << "1:delete dishes by ID\n" << "2:delete dishes by name" << endl;
	cout << "Please input 1 or 2: ";
	t = getInt();
	if (t == 1) {
		cout << "Please input the id want to delete." << endl;
		id = getInt();


		if (findDishesByID(menu, id) == 0) {
			cout << "Sorry, we cannot find the ID in the menu." << endl;
			return menu;
		}

		menu = deleteDishesByID(menu, id);
	}
	if (t == 2) {
		cout << "Please input the name want to delete." << endl;
		name = getString();

		if (findDishesByName(menu, name) == 0) {
			cout << "Sorry, we cannot find the name in the menu." << endl;
			return menu;
		}

		menu = deleteDishesByName(menu, name);
	}
	if (t != 1 && t != 2) cout << "Please input 1 or 2" << endl;
	return menu;
}

vector<Dishes> Chef::deleteDishesByID(vector<Dishes> menu, int did) {
	vector<Dishes> emp;
	for (Dishes s : menu) {
		if (s.id != did) {
			emp.push_back(s);
		}
	}
	return emp;
}

vector<Dishes> Chef::deleteDishesByName(vector<Dishes> menu, string dname) {
	vector<Dishes> emp;
	for (Dishes s : menu) {
		if (s.name != dname) {
			emp.push_back(s);
		}
	}
	return emp;
}



