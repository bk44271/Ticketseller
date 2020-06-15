#include <vector>
using namespace std;

#ifndef __Transakcja_h__
#define __Transakcja_h__

// #include "buyer.h"
// #include "seller.h"
#include "bilet.h"

class buyer;
class seller;
class bilet;
class Transakcja;

class Transakcja
{
	private: int _iD;
	private: string _data_tran;
	public: buyer* _unnamed_buyer_;
	public: seller* _unnamed_seller_;
	public: std::vector<bilet*> _bilet;
};

#endif
