//============================================================================
// Name        : Pair.cpp
// Author      : Андрей Ракитин
// Version     :
// Copyright   :
// Description : Методы класса Pair, использующие кейворд template
//============================================================================
#include "Header.h"

using namespace std;

template<typename T1, typename T2>
void Pair<T1, T2>::displayPair() const{
	cout<<Pair<T1, T2>::first_element<<" "<<Pair<T1, T2>::second_element<<endl;
}

