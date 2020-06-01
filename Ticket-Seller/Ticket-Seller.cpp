// Ticket-Seller.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "bilet.h"
#include "user.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
template <class T>
list<T> listfind(string s,list<T> l)
{
	list<T> f;
	for ( T it : l)
	{
		string tmp=it.to_str();
		size_t znal = tmp.find(s);
		if (znal != std::string::npos)
		{
			f.push_back(it);
		}
	}
	return f;
}

int main()
{
	char k='0';
	char n = '0';
	string login;
	string pass;
	string fraza;
	bool logged = 0;
	list<user> lu;
	list<wydarzenie> lw;
	list<miejsce> lm;
	list<artysta> la;
	lu.push_back(user());
	lu.push_back(user("login", "haslo", "tomek", "kupowacz"));
	lm.push_back(miejsce());
	la.push_back(artysta());
	lw.push_back(wydarzenie(&la.front(), &lm.front()));
	list<wydarzenie> wyniki;
	user* active;
	do
	{
		if (logged == 0)
		{
			cout << "::: TICKET-SELLER :::" << endl;
			cout << "Wybierz opcje" << endl;
			cout << "1 : zaloguj" << endl;
			cout << "2 : szukaj" << endl;
			cout << "t : test" << endl;
			cout << "k : zakoncz program" << endl;
			cin >> k;
			switch (k)
			{
			case '1':
				cout << "podaj login" << endl;
				cin >> login;
				cout << "podaj haslo" << endl;
				cin >> pass;
				logged = 1;
				break;
			case '2':
				cout << "podaj szukana fraze" << endl;
				break;
			case 't':
				cout << "przeprowadzamy tescik" << endl;
				active = &lu.front();
				lw.front().addbilet(1,100,0,active);
				active = &lu.back();
				wyniki = listfind("test", lw);
				cout << "wynik wyszukiwania:" << endl;
				cout << wyniki.front().to_str() << endl;
				lw.front().buybilet(lw.front()._bilet.front(), active);
				cout << active->zakupione.front()->to_str()<<endl;
				break;
			case 'k':
				cout << "Do Zobaczenia :)" << endl;
				break;
			}
		}
		else
		{
			cout << "::: TICKET-SELLER :::" << endl;
			cout << "witaj " << login << endl;
			cout << "Wybierz opcje" << endl;
			cout << "1 : przegladaj subskrypcje" << endl;
			cout << "2 : szukaj" << endl;
			cout << "k : zakoncz program" << endl;
			cin >> k;
			switch (k)
			{
			case '1':
				cout << "Twoje Subskrypcje" << endl;
				//wyswietlanie subskrybcji
				break;
			case '2':
				cout << "podaj szukana fraze" << endl;
				cout << "wybierz poprawny wynik jeżeli go nie ma wcisnij 'p'" << endl;
				cin >> fraza;
				//szukanie wydarzen zwraca liste
				do
				{
					cin >> n;
					if (n != 'p')
					{
						cout << "co chcesz zrobic?" << endl;
						cout << "1: dodaj bilet" << endl;
						cout << "2: kup bilet" << endl;
						cout << "3: subskrybuj" << endl;
						cout << "p: powrot" << endl;
						switch (n)
						{
						case '1':
							//dodawanie biletu
							break;
						case '2':
							//kupowanie biletu
							break;
						case '3':
							// subskrybowanie
							break;
						}
					}

				} while (n != 'p');
				break;
			case 'k':
				cout << "Do Zobaczenia :)" << endl;
				break;
			}
		}
		}while (k != 'k');
	
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
