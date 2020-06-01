#include <vector>
using namespace std;
#include "pch.h"
#include "bilet.h"
#include "Transakcja.h"
#include "wydarzenie.h"
#include "ticket_seller.h"

bilet::bilet() {
	_iD = 1;
	_cena = 1;
	_weryfikacja = 0;
}
bilet::bilet(wydarzenie* w) {
	_iD = 1;
	_cena = 1;
	_weryfikacja = 0;
	_wydarzenie = w;
	w->_bilet.push_back(this);
}
bilet::bilet(int id,float cena,bool wer,wydarzenie* w,user* spr) {
	_iD = id;
	_cena = cena;
	_weryfikacja = wer;
	_wydarzenie = w;
	w->_bilet.push_back(this);
	_sprzedajacy = spr;
}
string bilet::to_str()
{
	string wynik;
	wynik.append("ID:");
	wynik.append(to_string(_iD));
	wynik.append(" cena:");
	wynik.append(to_string(_cena));
	wynik.append(" weryfikacja:");
	wynik.append(to_string(_weryfikacja));
	return wynik;
}
