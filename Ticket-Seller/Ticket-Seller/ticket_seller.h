
#ifndef __ticket_seller_h__
#define __ticket_seller_h__

// #include "user.h"
// #include "artysta.h"
// #include "wydarzenie.h"
// #include "bilet.h"
// #include "miejsce.h"

class user;
class artysta;
class wydarzenie;
class bilet;
class miejsce;
class ticket_seller;

class ticket_seller
{
	private: int _attribute;
	private: int _iD;
	public: user* _unnamed_user_;
	public: artysta* _unnamed_artysta_;
	public: wydarzenie* _unnamed_wydarzenie_;
	public: bilet* _unnamed_bilet_;
	public: miejsce* _unnamed_miejsce_;
};

#endif
