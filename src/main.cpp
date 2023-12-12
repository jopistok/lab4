//============================================================================
// Name        : main.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Основной исполняемый файл
//============================================================================

#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru-RU");
	int* option = new int;
	string* addData = new string;
	string* rmData = new string;
	string* modData = new string;
	StockInfo* info = new StockInfo;
	info->set_dataFileName("product.txt");
	info->set_logFileName("output.txt");
	fstream logFile = info->connectToLogFile();
	logFile<<"Программа запущена"<<endl;

	bool working = true;
	bool menu = true;
	while(working){
		if(menu){
			call_menu();
		}
		(cin>>*option).get();
		switch(*option){
			case 1:
				info->initDatabaseFromFile();
				cout<<"Инициализация выполнена"<<endl;
				break;
			case 2:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				cout<<"Выберите категорию сортировки"<<endl;
				cout<<"1. Название"<<endl;
				cout<<"2. Стоимость"<<endl;
				cout<<"3. Количество"<<endl;
				(cin>>*option).get();
				sort_option(info, option);
				break;
			case 3:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				cout<<"Выберите категорию поиска"<<endl;
				cout<<"1. Название"<<endl;
				cout<<"2. Стоимость"<<endl;
				cout<<"3. Количество"<<endl;
				print_search(search_option(info));
				break;
			case 4:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				cout<<"Введите информацию о продукте в регламентированном формате"<<endl;
				cout<<"Название; Стоимость; Количество"<<endl;
				getline(cin, *addData);
				info->addProduct(s_to_p(*addData));
				break;
			case 5:
				cout<<"Введите название удаляемого продукта"<<endl;
				getline(cin, *rmData);
				info->removeProduct(*rmData);
				break;
			case 6:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				cout<<"Введите название изменяемого продукта"<<endl;
				getline(cin, *modData);
				info->modifyProduct(*modData);
				break;
			case 7:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				info->saveToFile();
				cout<<"Данные сохранены"<<endl;
				break;
			case 8:
				if(info->getSize() == 0){
					cerr<<"База данных не инициализирована"<<endl;
					break;
				}
				info->printDatabase();
				break;
			case 9:
				menu = !menu;
				cout<<"Теперь меню не выводится после каждой операции. Для того, чтобы обратить изменения, снова введите 9"<<endl;
				break;
			case 0:
				working = false;
				break;
			default:
				cerr<<"Неверно введен ключ команды"<<endl;
		}
	}

	logFile<<"Программа завершена"<<endl<<endl;
	logFile.close();
	delete option;
	delete addData;
	delete rmData;
	delete info;
	return 0;
}


