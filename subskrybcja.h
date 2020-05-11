#include <vector>
using namespace std;

#ifndef __subskrybcja_h__
#define __subskrybcja_h__

#include "user.h"
#include "wydarzenie.h"
#include "artysta.h"
#include "miejsce.h"

class user;
class wydarzenie;
class artysta;
class miejsce;
class subskrybcja;

class subskrybcja
{
	private: int _iD;
	public: std::vector<user*> _user;
	public: std::vector<wydarzenie*> _wyd;
	public: std::vector<artysta*> _artysta;
	public: std::vector<miejsce*> _miejsce;
};

#endif
