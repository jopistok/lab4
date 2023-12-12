//============================================================================
// Name        : Clothing.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Методы класса Clothing, использующие наследование от класса Product
//============================================================================
#include "Header.h"

using namespace std;

Clothing::Clothing(const string& n, const double& p, const int q): Product(n,p,q) {}

void Clothing::displayInfo() const{
	cout<<"Название одежды: "<<Name<<"\nСтоимость за единицу: "<<Price<<"\nКоличество одежды на складе: "<<Quantity<<endl;
}

Clothing::~Clothing(){}
