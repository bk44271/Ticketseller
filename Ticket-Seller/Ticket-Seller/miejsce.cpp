#include <string>
#include <vector>
using namespace std;
#include "pch.h"
#include "miejsce.h"
#include "wydarzenie.h"
#include "subskrybcja.h"
#include "ticket_seller.h"

miejsce::miejsce() {
	_iD = 1;
	_nazwa = "testowe miejsce";
}
string miejsce::to_str()
{
	{
		string wynik;
		wynik.append(to_string(_iD));
		wynik.append("::");
		wynik.append(_nazwa);
		return wynik;
	}
}