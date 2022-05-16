#pragma once
#include<fstream>
#include"Dishes.h";

class PerInRes
{
private:
	vector<Dishes> menu;

protected:
	//�鿴�˵�
	//�麯������̬
	//��chef��manager�����չʾ�˵�cost������customer���ܿ���
	virtual void showMenu(vector<Dishes> menu);
	virtual void showMenuNomally(vector<Dishes> t);
	virtual void showPopularDishes(vector<Dishes> t); //չʾʱ�����ܻ�ӭ�̶Ƚ�������,�ɵ���sort����
	vector<Dishes> sort(vector<Dishes> t);

	//��������ĳЩ�ؼ��ֵĲ˵������Ϣ����������ʾcost
	//�麯������̬
	//id,name,�˵�ԭ���ϣ��۸�price��
	virtual void searchDishes(vector<Dishes> t);
	virtual void searchDishesByID(vector<Dishes> t, int did);
	virtual void searchDishesByName(vector<Dishes> t, string name);
	virtual void searchDishesByRaw(vector<Dishes> t, string RawMaterialName);//չʾ���а���ԭ���ϵ�������RawMaterialName�Ĳ�
	virtual void searchDishesByPrice(vector<Dishes> t, double price);//չʾ���м۸���price�Ĳ�


	//�ж�Ҫ�ҵĲ��ڲ���ĳһ��vector<Dishes>��
	//���ݲ˵�id��name
	bool findDishesByID(vector<Dishes> t, int did);
	bool findDishesByName(vector<Dishes> t, string name);

	//read files
	vector<Dishes> loadMenu(string menuaddress);
	vector<RawMaterial> loadRlist(string address);
	//vector<Customer> loadClist(string address);����customer��mananger�����ᱨ��


	//write files 
	void outputMenu(vector<Dishes> menu, string address);
	void outputRlist(vector<RawMaterial> rlist, string address);
	//void outputClist(vector<Customer> clist, string address);����customer��mananger�����ᱨ��
	

public:
	//����ĳЩ�ض������͵�ֵ
	//���û����벢����
	//int, string, double,
	int getInt();//��������������-1�����벻������ʱ��
	string getString();//�������һ����Ϊ�ַ�������
	double getPosDouble();//��������double������-1�����벻��doubleʱ��
	vector<string> stringSplit(string str, char cr);//����cr��string�ֽ⣬������vector<string>;���str��û��cr���ͷ���str

	//���������Ľӿ�
	//void PerInResMain();
};



