#include <string>
#include <vector>
using namespace std;

#ifndef __wydarzenie_h__
#define __wydarzenie_h__

#include "subskrybcja.h"
// #include "ticket_seller.h"
#include "miejsce.h"
#include "bilet.h"
#include "artysta.h"

class subskrybcja;
class ticket_seller;
class miejsce;
class bilet;
class artysta;
class wydarzenie;

class wydarzenie
{
	private: int _iD;
	private: date _data;
	private: string _nazwa;
	public: std::vector<subskrybcja*> _sub;
	public: ticket_seller* _unnamed_ticket_seller_;
	public: std::vector<miejsce*> _miejsce;
	public: std::vector<bilet*> _bitel;
	public: std::vector<artysta*> _artysta;
};

#endif
