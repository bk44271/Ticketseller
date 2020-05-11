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

class bilet
{
	private: int _iD;
	private: float _cena;
	private: bool _weryfikacja;
	public: Transakcja* _transakcja;
	public: std::vector<wydarzenie*> _wydarzenie;
	public: ticket_seller* _unnamed_ticket_seller_;
};

#endif
