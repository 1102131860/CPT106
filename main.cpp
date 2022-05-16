#include"Manager.h"
void arrange(string str) {
	cout << "*\t" << str << setw(45 - str.size()) << setfill(' ') << "\t*\n";
}

int main()
{
	PerInRes p;
	string mpw = "abc123";
	string chpw = "123abc";
	cout << setw(57) << setfill('*') << '*' << endl;
	arrange("Welcome to Restaurant Manager system!");
	arrange("Choose your role in the restaurant");
	arrange("1. Customer");
	arrange("2. Chef");
	arrange("3. Manager");
	arrange("4. Exit");
	cout << setw(57) << setfill('*') << '*' 
		<< setw(2) << setfill(' ') << " " << endl;
	cout << "Please enter 1,2,3 or 4: ";
	int choice = p.getInt();
	switch (choice)
	{
	case 1: 
	{
		Customer c;
		c.CustomerMain(c);
		break;
	}
	case 2:
	{
		cout << "Please enter the password for chef: " << endl;
		string pw1 = p.getString();
		if (pw1 == chpw) {
			Chef ch;
			ch.ChefMain();
			break;
		}else {
			cout << "Wrong password!" << endl;
			break;
		}
	}
	case 3:
	{
		cout << "Please enter the password for manager: " << endl;
		string pw2 = p.getString();
		if (pw2 == mpw) {
			Manager m;
			m.ManagerMain();
			break;
		}else  {
			cout << "Wrong password!" << endl;
			break;
		}
	}
	case 4:
		cout << "Successfully log out restaurant manager system!" << endl;
		exit(0);
		break;
	default:
		cout << "Invalid input" << endl;
	}
}

