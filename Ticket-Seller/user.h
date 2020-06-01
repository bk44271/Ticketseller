#include <exception>
#include <string>
#include <vector>
#include <list>
using namespace std;

#ifndef __user_h__
#define __user_h__

// #include "ticket_seller.h"
#include "subskrybcja.h"

class ticket_seller;
class subskrybcja;
class user;
class bilet;

class user
{
	private: int _iD;
	private: string _login;
	private: string _has³o;
	private: string _imie;
	private: string _nazw;
	private: int _rola;
	public: ticket_seller* _unnamed_ticket_seller_;
	public: std::vector<subskrybcja*> _sub;
public: list<bilet*> zakupione;
public: list<bilet*> sprzedawane;


	public: user();
public:user(string l, string h, string i, string n);
};

#endif
