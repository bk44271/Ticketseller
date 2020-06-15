#include <exception>
using namespace std;

#ifndef __buyer_h__
#define __buyer_h__

// #include "Transakcja.h"
#include "user.h"

class Transakcja;
// class user;
class buyer;

class buyer: public user
{
	public: Transakcja* _tran;

			buyer();
};

#endif
