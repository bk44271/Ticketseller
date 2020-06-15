#include <vector>
using namespace std;

#ifndef __bilet_h__
#define __bilet_h__

// #include "Transakcja.h"
#include "wydarzenie.h"
// #include "ticket_seller.h"

class Transakcja;
class wydarzenie;
class ticket_seller;
class bilet;
class user;

class bilet
{
	private: int _iD;
	private: float _cena;
	private: bool _weryfikacja;
	public: Transakcja* _transakcja;
	public: wydarzenie* _wydarzenie;
public: user* _sprzedajacy;
	public: ticket_seller* _unnamed_ticket_seller_;
			bilet();
			bilet(wydarzenie* w);
			bilet(int id, float cena, bool wer, wydarzenie* w,user* spr);
			string to_str();
};

#endif
