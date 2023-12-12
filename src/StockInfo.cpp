//============================================================================
// Name        : StockInfo.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Методы класса StockInfo, который отображает сущность базы данных
//============================================================================
#include "Header.h"

using namespace std;


StockInfo::StockInfo(){}

void StockInfo::set_dataFileName(const string& name){
	dataFileName = name;
}

void StockInfo::set_logFileName(const string& name){
	logFileName = name;
}

int StockInfo::getSize(){
	return database.size();
}

fstream StockInfo::connectToLogFile(){
	fstream logFile(logFileName, ios::app);
	if(!logFile.is_open()){
		cerr<<"Ошибка открытия файла учета активности"<<endl;
		exit(4);
	}
	return logFile;
}

ifstream StockInfo::readFromDataFile(){
	ifstream dataFile(dataFileName, ios::app);
	if(!dataFile.is_open()){
		cerr<<"Ошибка открытия файла базы данных"<<endl;
		exit(1);
	}
	return dataFile;
}

ofstream StockInfo::writeToDataFile(){
	ofstream dataFile(dataFileName);
	if(!dataFile.is_open()){
		cerr<<"Ошибка открытия файла базы данных"<<endl;
		exit(1);
	}
	return dataFile;
}

void StockInfo::sortName(){
	fstream logFile = StockInfo::connectToLogFile();
	sort(database.begin(), database.end(), [](const Product& a, const Product& b){return a.getName() < b.getName();});
	logFile<<"Выполнена сортировка по параметру Название"<<endl;
	logFile.close();
}

void StockInfo::sortPrice(){
	fstream logFile = StockInfo::connectToLogFile();
	sort(database.begin(), database.end(), [](const Product& a, const Product& b){return a.getPrice() > b.getPrice();});
	logFile<<"Выполнена сортировка по параметру Стоимость"<<endl;
	logFile.close();
}

void StockInfo::sortQuantity(){
	fstream logFile = StockInfo::connectToLogFile();
	sort(database.begin(), database.end(), [](const Product& a, const Product& b){return a.getQuantity() > b.getQuantity();});
	logFile<<"Выполнена сортировка по параметру Количество"<<endl;
	logFile.close();
}

void StockInfo::addProduct(const Product& p){
	fstream logFile = StockInfo::connectToLogFile();
	database.push_back(p);
	logFile<<"Выполнено добавление продукта в базу данных, изменения в файле не сохранены"<<endl;
	logFile.close();
}

void StockInfo::removeProduct(const string& name){
	fstream logFile = StockInfo::connectToLogFile();
	for(auto it = database.begin(); it < database.end(); it++){
		if (it->getName() == name){
			database.erase(it);
			cout<<"Элемент удален"<<endl;
		}
	}
	logFile<<"Выполнено удаление продукта из базы данных, изменения в файле не сохранены"<<endl;
	logFile.close();
}

vector<Product*> StockInfo::search(const string& data){
	fstream logFile = StockInfo::connectToLogFile();
	vector<Product*> out = {};
	for (auto& i: database){
		if(i.getName() == data){
			out.push_back(&i);
		}
	}
	logFile<<"Выполнен поиск продукта по Названию "<<data<<endl;
	logFile.close();
	if (out.size() == 0){
		out.push_back(nullptr);
	}
	return out;
}

vector<Product*> StockInfo::search(const double& data){
	fstream logFile = StockInfo::connectToLogFile();
	vector<Product*> out = {};
	for (auto& i: database){
		if(i.getPrice() == data){
			out.push_back(&i);
		}
	}
	logFile<<"Выполнен поиск продукта по Стоимости "<<data<<endl;
	logFile.close();
	if (out.size() == 0){
		out.push_back(nullptr);
	}
	return out;
}

vector<Product*> StockInfo::search(const int& data){
	fstream logFile = StockInfo::connectToLogFile();
	vector<Product*> out = {};
	for (auto& i: database){
		if(i.getQuantity() == data){
			out.push_back(&i);
		}
	}
	logFile<<"Выполнен поиск продукта по Количеству "<<data<<endl;
	logFile.close();
	if (out.size() == 0){
		out.push_back(nullptr);
	}
	return out;
}

void StockInfo::modifyProduct(const string& modData){
	fstream logFile = StockInfo::connectToLogFile();
	Product* p = StockInfo::search(modData)[0];
	unsigned option;
	if(p == nullptr){
		cerr<<"Товар с таким именем не найден"<<endl;
		return;
	}
	cout<<"Выберите аттрибут товара, который Вы хотели бы изменить"<<endl;
	cout<<"1. Наименование"<<endl;
	cout<<"2. Стоимость"<<endl;
	cout<<"3. Колличество"<<endl;
	(cin>>option).get();
	switch(option){
	case 1:
	{
		cout<<"Введите новое Наименование товара"<<endl;
		string sdata;
		getline(cin, sdata);
		p->modifyName(sdata);}
		break;
	case 2:
	{
		cout<<"Введите новую Стоимость товара"<<endl;
		double ddata;
		cin>>ddata;
		p->modifyPrice(ddata);}
		break;
	case 3:
	{
		cout<<"Введите новое Количество товара"<<endl;
		int idata;
		cin>>idata;
		p->modifyPrice(idata);}
		break;
	default:
		cerr<<"Неверно введен параметр"<<endl;
		logFile<<"Программа завершена принудительно. Код ошибки: 5"<<endl;
		logFile.close();
		exit(5);
	}
	cout<<"Товар модифицирован"<<endl;
	logFile<<"Товар модифицирован"<<endl;
	logFile.close();
}

void StockInfo::initDatabaseFromFile(){
	database = vector<Product>{};
	string line;
	fstream logFile = StockInfo::connectToLogFile();
	ifstream dataFile = StockInfo::readFromDataFile();
	while(getline(dataFile, line)){
		database.push_back(s_to_p(line));
	}
	logFile<<"База данных инициализирована"<<endl;
	logFile.close();
	dataFile.close();
}

void StockInfo::saveToFile(){
	fstream logFile = StockInfo::connectToLogFile();
	ofstream dataFile = StockInfo::writeToDataFile();
	for(const auto& i: database){
		dataFile<<i<<endl;
	}
	logFile<<"База данных сохранена"<<endl;
	dataFile.close();
	logFile.close();
}

void StockInfo::printDatabase(){
	fstream logFile = StockInfo::connectToLogFile();
	if (database.size() == 0){
		cerr<<"База пуста, возможно Вы её не инициализовали"<<endl;
		logFile<<"Попытка вывода пустой базы данных"<<endl;
		logFile.close();
		return;
	}
	for(const auto& i: database){
		cout<<i<<endl;
	}
	logFile<<"База данных ввыведена в консоль"<<endl;
	logFile.close();
}

StockInfo::~StockInfo(){}
