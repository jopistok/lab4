/*
 * Header.h
 *
 *      Author: Андрей Ракитин
 * Основной заголовочный файл
 */

#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

class Product{
public:
	string Name;
	double Price;
	int Quantity;
public:
	Product(const std::string& n, const double& p, const int& q);
	virtual void displayInfo() const;
	string getName() const;
	double getPrice() const;
	int getQuantity() const;
	void modifyName(const string& n);
	void modifyPrice(const double& p);
	void modifyQuantity(const int& q);
	virtual ~Product();
};

ostream& operator<<(ostream& os, const Product& p);

class Clothing : public Product{
public:
	Clothing(const string& n, const double& p, const int q);
	void displayInfo() const override;
	~Clothing();
};

class Electronics : public Product{
public:
	Electronics(const string& n, const double& p, const int q);
	void displayInfo() const override;
	~Electronics();
};

template<typename T1, typename T2>
class Pair{
public:
	T1 first_element;
	T2 second_element;
public:
	void displayPair() const;
};

class StockInfo{
private:
	vector<Product> database;
	string dataFileName;
	string logFileName;
public:
	StockInfo();
	void set_dataFileName(const string& name);
	void set_logFileName(const string& name);
	int getSize();
	fstream connectToLogFile();
	ifstream readFromDataFile();
	ofstream writeToDataFile();
	void sortName();
	void sortPrice();
	void sortQuantity();
	void addProduct(const Product& p);
	void removeProduct(const string& name);
	vector<Product*> search(const string& data);
	vector<Product*> search(const double& data);
	vector<Product*> search(const int& data);
	void modifyProduct(const string& modData);
	void initDatabaseFromFile();
	void saveToFile();
	void printDatabase();
	~StockInfo();
};

Product s_to_p(const string& s);

void sort_option(StockInfo* info, int* option);

vector<Product*> search_option(StockInfo* info);

void print_search(const vector<Product*>& p);

void call_menu();
#endif /* CLASSES_H_ */
