//============================================================================
// Name        : Electronics.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Методы класса Electronics, использующие наследование от класса Product
//============================================================================
#include "Header.h"

using namespace std;

Electronics::Electronics(const string& n, const double& p, const int q): Product(n,p,q) {}

void Electronics::displayInfo() const{
	cout<<"Название электроники: "<<Name<<"\nСтоимость за единицу: "<<Price<<"\nКоличество электроники на складе: "<<Quantity<<endl;
}

Electronics::~Electronics(){}
