#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class RawMaterial
{
public:
	string name = "Noname";
	double price = 0;

	//给manager,chif看的时候用
	void show();
};

