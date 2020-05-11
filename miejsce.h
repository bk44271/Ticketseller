#include <string>
#include <vector>
using namespace std;

#ifndef __miejsce_h__
#define __miejsce_h__

#include "wydarzenie.h"
#include "subskrybcja.h"
// #include "ticket_seller.h"

class wydarzenie;
class subskrybcja;
class ticket_seller;
class miejsce;

class miejsce
{
	private: int _iD;
	private: string _nazwa;
	public: std::vector<wydarzenie*> _wydarzenia;
	public: std::vector<subskrybcja*> _sub;
	public: ticket_seller* _unnamed_ticket_seller_;
};

#endif
