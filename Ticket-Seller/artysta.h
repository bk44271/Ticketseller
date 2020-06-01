#include <string>
#include <vector>
using namespace std;

#ifndef __artysta_h__
#define __artysta_h__

#include "wydarzenie.h"
#include "subskrybcja.h"
// #include "ticket_seller.h"

class wydarzenie;
class subskrybcja;
class ticket_seller;
class artysta;

class artysta
{
	private: int _iD;
	private: string _idartysty;
	private: string _nazwa;
	public: std::vector<wydarzenie*> _wydarzenie;
	public: std::vector<subskrybcja*> _sub;
	public: ticket_seller* _unnamed_ticket_seller_;
			artysta();
};

#endif
