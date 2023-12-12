//============================================================================
// Name        : StockInfo.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Вспомогательные функции
// s_to_p() -- Перевод строки в объект класса Product
// sort_option() -- Вызов корректной сортировки StockInfo
// search_option() -- Формирование вектора объектов класса Product, удовлетворяющих условию поиска
// print_search() -- Вывод search_option() в консоль
// call_menu() -- Вывод меню в консоль
//============================================================================
#include "Header.h"

using namespace std;


Product s_to_p(const string& s){
	string* word = new string;
	*word = "";
	vector<string>* words = new vector<string>;
	for(const char i: s){
		if (i == ';'){
			words->push_back(*word);
			*word = "";
		}
		else{
			if(((*word).empty())&(i == ' ')){
				continue;
			}
			*word = *word + i;
		}
	}
	words->push_back(*word);
	Product out((*words)[0], stod((*words)[1]), stoi((*words)[2]));
	delete words;
	delete word;
	return out;
}

void sort_option(StockInfo* info, int* option){
	switch(*option){
	case 1:
		info->sortName();
		break;
	case 2:
		info->sortPrice();
		break;
	case 3:
		info->sortQuantity();
		break;
	default:
		info->saveToFile();
		cerr<<"Неверный ключ сортировки"<<endl;
		exit(2);
	}
}

vector<Product*> search_option(StockInfo* info){
	int* search_option = new int;
	string* data = new string;
	vector<Product*> out;
	(cin>>*search_option).get();
	switch(*search_option){
	case 1:
		cout<<"Введите значение"<<endl;
		getline(cin, *data);
		out = info->search(*data);
		break;
	case 2:
		cout<<"Введите значение"<<endl;
		getline(cin, *data);
		out = info->search(stod(*data));
		break;
	case 3:
		cout<<"Введите значение"<<endl;
		getline(cin, *data);
		out = info->search(stoi(*data));
		break;
	default:
		cerr<<"Неверный ключ поиска"<<endl;
		exit(3);
		break;
	}
	delete search_option;
	delete data;
	return out;
}

void print_search(const vector<Product*>& p){
	if(!(p.size() == 0)){
		for(const auto& i: p){
			cout<<*i<<endl;
		}
	}
	else{
		cout<<"Совпадений не найдено"<<endl;
	}
}

void call_menu(){
	cout<<endl<<"Меню выбора опции"<<endl;
	cout<<"1. Инициализация базы данных из файла"<<endl;
	cout<<"2. Сортировка по выбранному аргументу"<<endl;
	cout<<"3. Поиск по значению"<<endl;
	cout<<"4. Добавление в базу данных"<<endl;
	cout<<"5. Удаление из базы данных"<<endl;
	cout<<"6. Изменение данных о продукте"<<endl;
	cout<<"7. Сохранение данных"<<endl;
	cout<<"8. Вывод базы данных в консоль"<<endl;
	cout<<"9. Переключить вывод меню"<<endl;
	cout<<"0. Выход из программы"<<endl;
}
