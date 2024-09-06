#pragma once
#include<vector>
#include<string>
#include"RawMaterial.h";

class Dishes
{
public:
	string name = "NoName";
	int id = 0;
	double price = 0;
	double cost = 0;
	vector<RawMaterial> rawVector;
	int numOrdered = 0;

	bool operator > (Dishes d);
	string getRawName(vector<RawMaterial> r);
	void showWOTcost();
	void showAll();
};

