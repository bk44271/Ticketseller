// Ticket-Seller.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "bilet.h"
#include "user.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
// Wyszukiwanie w liscie
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
//zwraca pierwszy szukany element z listy
template <class T>
T* firstinlistfind(string s, list<T> l)
{
	list<T> f;
	for (T it : l)
	{
		string tmp = it.to_str();
		size_t znal = tmp.find(s);
		if (znal != std::string::npos)
		{
			return &it;
		}
	}
	return NULL;
}
//PU logowanie
user* log_in(string login, string haslo, list<user> users)
{
	for (user it : users) 
	{
		if(it.getlogin() == login) 
		{
			if (it.gethaslo() == haslo) 
			{
				cout << "zalogowano" << endl;
				cout << "witaj " << it.getimie();
				return &it;
			}
			else
			{
				cout << "zle haslo"<<endl;
				return NULL;
			}
		}
	}
cout << "niepoprawny login" << endl;
return NULL;
}
//PU(admin) dodawanie nowego wydarzenia
void nowe_wydrzenie(list<wydarzenie> lw,list<artysta> lu,list<miejsce> lm)
{
	char n;
	string nazwa;
	int iD;
	string data;
	string art;
	string msc;
	artysta* tmp=NULL;
	miejsce* tmpm = NULL;
	cout << "::Dodawanie nowego wydarzenia::" << endl;
	cout << "podaj nazwe wydarzenia" << endl;
	cin >> nazwa;
	cout << "podaj id wydarzenia" << endl;
	cin>>iD;
	cout << "podaj date wydarzenia format DD/MM/RRRR"<<endl;
	cin>>data;
	do
	{
		cout << "dodaj artyste(wpisz id lub data)" << endl;
		cin >> art;
		tmp = firstinlistfind(art, lu);
		if (tmp != NULL)
		{
			cout << tmp->to_str() << endl;
			cout << "jesli to poprawny wynik wcisnij `t`" << endl;
			cout << "jesli chcesz powtorzyc szukanie zeby znalezc innego artyste wcisnij `p`"<<endl;
			cin >> n;
		}
		else
		{
			cout << "nie znaleziono takiego artysty" << endl;
			cout << "podaj poprawnego artyste" << endl;
			n = 'p';
		}
	} while (n == 'p');
	do
	{
		cout << "dodaj miejsce(wpisz id lub data)" << endl;
		cin >> msc;
		tmpm = firstinlistfind(msc, lm);
		if (tmpm != NULL)
		{
			cout << tmpm->to_str() << endl;
			cout << "jesli to poprawny wynik wcisnij `t`" << endl;
			cout << "jesli chcesz powtorzyc szukanie zeby znalezc inne miejsce wcisnij `p`" << endl;
			cin >> n;
		}
		else
		{
			cout << "nie znaleziono takiego artysty" << endl;
			cout << "podaj poprawnego artyste" << endl;
			n = 'p';
		}
	} while (n == 'p');
	lw.push_back(wydarzenie(iD, nazwa, data, tmp, tmpm));
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
	lu.push_back(user("admin", "admin", "Kacper", "Buczek"));
	lu.back().set_admin();
	lm.push_back(miejsce());
	la.push_back(artysta());
	lw.push_back(wydarzenie(&la.front(), &lm.front()));
	string szukane;
	list<wydarzenie> wyniki;
	user* active=NULL;
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
				active = log_in(login,pass,lu);
				if (active != NULL)
				{
					logged = 1;
				}
				break;
			case '2':

				cout << "podaj szukana fraze" << endl;
				cin >> szukane;
				wyniki = listfind(szukane, lw);
				for (wydarzenie it : wyniki)
				{
					cout << it.to_str()<<endl;
				}
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
			if (active->admin = 0)
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
			else
			{
				cout << "::: TICKET-SELLER :::" << endl;
				cout << "Szanowny pan Admin :)" << endl;
				cout << "Wybierz opcje" << endl;
				cout << "1 : dodaj wydarzenie" << endl;
				cout << "2 : dodaj artyste" << endl;
				cout << "3 : dodaj miejsce" << endl;
				cout << "4 : szukaj" << endl;
				cout << "k : zakoncz program" << endl;
				cin >> k;
				switch (k)
				{
				case '1':
					nowe_wydrzenie(lw,la,lm);
					break;
				case '2':

					break;
				case '4':
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
