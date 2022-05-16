#pragma once
#include"PerInRes.h";

class Chef : public PerInRes
{
private:
	vector<RawMaterial> rlist;
	vector<Dishes> menu;

protected:
	//�������ԭ���ϵ������Ϣ
	void browseRawMateroal(vector<RawMaterial> list);

	//�鿴Ҫ�ҵ�ԭ����r�ڲ���list��
	//bool findRawMaterial(vector<RawMaterial> list);//���ü̳�����inputRawMaterialName()
	//bool findRawMaterial(vector<RawMaterial> list, string rname);//��������

	//�鿴ĳһ��ԭ����r�������Ϣ
	void searchRawMaterial(vector<RawMaterial> list);//���ü̳�����inputRawMaterialName()
	void searchRawMaterial(vector<RawMaterial> list, string rname);//��������

	//�鿴�˵�
	//����overloading
	//���Կ��������йز�����˵���Ϣ������cost�ɱ�
	void showMenu(vector<Dishes> t) override;
	void showPopularDishes(vector<Dishes> t) override; //չʾʱ�����ܻ�ӭ�̶Ƚ�������

	//��������ĳЩ�ؼ��ֵĲ˵������Ϣ
	//����overloading
	//���Կ��������й���Ϣ������cost�ɱ�
	void searchDishes(vector<Dishes>) override;
	void searchDishesByID(vector<Dishes> t, int did) override;
	void searchDishesByName(vector<Dishes> t, string name) override;
	void searchDishesByRaw(vector<Dishes> t, string RawMaterialName) override;//չʾ���а���ԭ���ϵ�������RawMaterialName�Ĳ�
	void searchDishesByPrice(vector<Dishes> t, double price) override;//չʾ���м۸���price�Ĳ�

	//���Ӳ˵���Ĳ�
	//���ж��ǲ����Ѿ��ڲ˵�����ܼ�ͬ���Ĳ�
	//����һ��dish��Ȼ��ӵ�menu��
	vector<Dishes> addDishes(vector<Dishes> menu);

	//�޸Ĳ˵���Ĳ�
	//������ԭ���ϣ����ۣ��ɱ�
	//����ID����nameѡ��ͬ�ĺ���
	vector<Dishes> modifyDishes(vector<Dishes> menu);//���ü̳�����inputDishesID()��inputRawMaterialName();
	/*vector<Dishes> modifyDishesByID(vector<Dishes> menu, int did);
	vector<Dishes> modifyDishesByname(vector<Dishes> menu, string dname);*/

	//ɾ���˵���Ĳ�
	//����ID����nameѡ��ͬ�ĺ���
	vector<Dishes> deleteDishes(vector<Dishes> menu);//���ü̳�����inputDishesID()��inputRawMaterialName();
	vector<Dishes> deleteDishesByID(vector<Dishes> menu, int did);
	vector<Dishes> deleteDishesByName(vector<Dishes> menu, string dname);


public:
	//�뺯�������ӿ�
	void ChefMain() {
		menu = loadMenu("menu.txt");
		rlist = loadRlist("rawmaterial.txt");

		cout << "\nRole: A Chef in the restaurant" << endl;
		cout << "Choose an option: " << endl;
		cout << "1. Browse RawMaterials" << endl;
		cout << "2. Search RawMaterial" << endl;
		cout << "3. Browse the Menu" << endl;
		cout << "4. Search dishes" << endl;
		cout << "5. Add dish into Menu" << endl;
		cout << "6. Modify dish in the Menu" << endl;
		cout << "7. Delete dish from the Menu" << endl;
		cout << "8. Exits" << endl;

		cout << "Input an integer between 1 to 8: ";
		int choice = getInt();
		switch (choice)
		{
		case 1:
			browseRawMateroal(rlist);
			break;
		case 2:
			searchRawMaterial(rlist);
			break;
		case 3:
			showMenu(menu);
			break;
		case 4:
			searchDishes(menu);
			break;
		case 5:
			menu = addDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 6:
			menu = modifyDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 7:
			menu = deleteDishes(menu);
			outputMenu(menu, "menu.txt");
			break;
		case 8:
			cout << "Chef has successfully exited out!" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid input\n" <<
				"Please input an integer between 1 to 8\n";
		}
		ChefMain();
	}

};

