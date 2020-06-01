#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "pch.h"
#include "wydarzenie.h"
#include "subskrybcja.h"
#include "ticket_seller.h"
#include "miejsce.h"
#include "bilet.h"
#include "artysta.h"

wydarzenie::wydarzenie() {
	_iD = 1;
	_nazwa = "testowe wydarzenie";
}
wydarzenie::wydarzenie(artysta* a,miejsce* m) {
	_iD = 1;
	_nazwa = "testowe wydarzenie";
	_artysta.push_back(a);
	_miejsce.push_back(m);
}

void wydarzenie::addbilet(int id,float cena,bool wer,user* u){
	bilet *b=new bilet(id,cena,wer,this,u);
	cout << "dodano nowy bilet do wydarzenia " << _nazwa << endl;
	_bilet.push_back(b);
	u->sprzedawane.push_back(b);
}

void wydarzenie::buybilet(bilet* b, user* u)
{
	cout << "zakupiono bilet z wydarzenia"<<endl;
	_bilet.remove(b);
	u->zakupione.push_back(b);
	b->_sprzedajacy->sprzedawane.remove(b);
}

string wydarzenie::to_str()
{
	string wynik;
	wynik.append(to_string(_iD));
	wynik.append("::");
	wynik.append(_nazwa);
	return wynik;
}