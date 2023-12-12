//============================================================================
// Name        : Product.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Методы класса Product, который отображает сущность определенной позиции на торговой точке
//============================================================================
#include "Header.h"

using namespace std;

Product::Product(const std::string& n, const double& p, const int& q): Name(n), Price(p), Quantity(q) {};
void Product::displayInfo() const{
	cout<<"Название товара: "<<Name<<"\nСтоимость за единицу: "<<Price<<"\nКоличество товара на складе: "<<Quantity<<endl;
}
string Product::getName() const {
	return Name;
}
double Product::getPrice() const {
	return Price;
}
int Product::getQuantity() const {
	return Quantity;
}
void Product::modifyName(const string& n){
	Name = n;
}
void Product::modifyPrice(const double& p){
	Price = p;
}
void Product::modifyQuantity(const int& q){
	Quantity = q;
}
Product::~Product(){}

ostream& operator<<(ostream& os, const Product& p){
	return os<<p.getName()<<"; "<<p.getPrice()<<"; "<<p.getQuantity();
}

template<typename T>
int maxLength(const vector<T>& vec){
	return max_element(vec.begin(), vec.end(), [](const T& a, const T& b){return length(to_string(a)) < length(to_string(b));});
}
