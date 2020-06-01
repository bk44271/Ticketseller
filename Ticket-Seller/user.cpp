#include <exception>
#include <string>
#include <vector>
using namespace std;
#include "pch.h"
#include "user.h"
#include "ticket_seller.h"
#include "subskrybcja.h"

 user::user() {
	 _login = 'test';
	 _has³o = 'test';
	 _imie = "Testek";
	 _nazw = "Testowski";
}
 user::user(string l, string h, string i, string n) 
 {
	 _login = l;
	 _has³o = h;
	 _imie = i;
	 _nazw = n;
 }
