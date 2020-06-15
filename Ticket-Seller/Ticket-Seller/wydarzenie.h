#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

#ifndef __wydarzenie_h__
#define __wydarzenie_h__

#include "subskrybcja.h"
// #include "ticket_seller.h"
#include "miejsce.h"
#include "bilet.h"
#include "artysta.h"
#include <ctime>

class subskrybcja;
class ticket_seller;
class miejsce;
class bilet;
class artysta;
class wydarzenie;

class wydarzenie
{
	private: int _iD;
	private: string _data;
	private: string _nazwa;
	public: std::vector<subskrybcja*> _sub;
	public: ticket_seller* _unnamed_ticket_seller_;
	public: std::vector<miejsce*> _miejsce;
	public: std::list<bilet*> _bilet;
	public: std::vector<artysta*> _artysta;
			wydarzenie();
			wydarzenie(artysta* a, miejsce* m);
			wydarzenie(int id, string nazwa,string data, artysta* a, miejsce* m);
			void addbilet(int id, float cena, bool wer,user* u);
			void buybilet(bilet* b, user* u);
			string to_str();
};

#endif
