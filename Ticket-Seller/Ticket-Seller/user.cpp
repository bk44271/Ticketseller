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
	 _has�o = 'test';
	 _imie = "Testek";
	 _nazw = "Testowski";
}
 user::user(string l, string h, string i, string n) 
 {
	 _login = l;
	 _has�o = h;
	 _imie = i;
	 _nazw = n;
	 admin = 0;
 }
 void user::set_admin()
 {
	 admin = 1;
 }
 string user::getimie()
 {
	 return _imie;
 }
 string user::gethaslo()
 {
	 return _has�o;
 }
 string user::getlogin()
 {
	 return _login;
 }
