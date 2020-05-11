#include <exception>
using namespace std;

#ifndef __seller_h__
#define __seller_h__

// #include "Transakcja.h"
#include "user.h"

class Transakcja;
// class user;
class seller;

class seller: public user
{
	public: Transakcja* _unnamed_Transakcja_;

	public: void operation();
};

#endif
