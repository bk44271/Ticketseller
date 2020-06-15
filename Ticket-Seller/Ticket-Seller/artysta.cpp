#include <string>
#include <vector>
using namespace std;
#include "pch.h"
#include "artysta.h"
#include "wydarzenie.h"
#include "subskrybcja.h"
#include "ticket_seller.h"

artysta::artysta() {
	_iD = 1;
	_nazwa = "test";
}
string artysta::to_str()
{
	{
		string wynik;
		wynik.append(to_string(_iD));
		wynik.append("::");
		wynik.append(_nazwa);
		return wynik;
	}
}