// C_zadania.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void zadanie1_1();
void zadanie1_2();
void zadanie1_3();
void zadanie1_4();
void zadanie1_5();
bool isBiggest(int, int, int);
void zadanie1_6();
float readFloatWithMessage(char[]);
char readCharWithMessage(char[]);

void zadanie2_1();
void zadanie2_1A();
void zadanie2_2();
void zadanie2_3();
void zadanie2_4();
void zadanie2_5();
void zadanie2_6();
void zadanie2_7();
void zadanie2_8();
void zadanie2_9();

void NewLine();
void NewLines(int);
void WriteBiggerNumber(int, int);
int Multiply(int, int);

int main()
{
	zadanie2_2();
	//// 3.1.
	//NewLine();

	//// 3.2.
	//NewLines(3);

	//// 3.3.
	//int x, y;
	//cin >> x >> y;
	//WriteBiggerNumber(x, y);

	//// 3.4.
	//int x, y;
	//cin >> x >> y;
	//cout << Multiply(x, y);
}

/* 1.1. Zadeklarowa� zmienne typu int, float, char. Przypisa� do nich warto��, wy�wietli� je na ekran. */
void zadanie1_1()
{
	int myInt;
	float myFloat;
	char myChar;

	myInt = 1;
	myFloat = 0.5;
	myChar = 'a';

	cout << myInt << endl;
	cout << myFloat << endl;
	cout << myChar << endl;
}

/* 1.2. Wy�wietli� zmienn� typu int na ekran. Nale�y u�y� metody printf i konstrukcji %d */
void zadanie1_2()
{
	int myVariable = 1;
	printf("%d Damian", myVariable);
}

/* 1.3. Pobra� od u�ytkownika liczb� x. Wy�wietli� kwadrat liczby x. */
void zadanie1_3()
{
	int x, x2;
	cin >> x;
	x2 = x * x;
	cout << x2;
}

/* 1.4. Zapozna� si� z instrukcjami warunkowymi (if, else if, else oraz switch). Pobra� od u�ywkownika liczb� i wy�wietli� informacj�, czy jest
ona: mniejsza, wi�ksza, czy r�wna 0. */
void zadanie1_4()
{
	int x;
	cin >> x;

	if (x > 0) cout << "x > 0";
	else if (x == 0) cout << "x = 0";
	else cout << "x < 0";
}

/* 1.5. Pobra� ud u�ytkownika 3 liczby (x1, x2, x3). Wy�wietli� informacj�, kt�ra z tych liczb jest najwi�ksza. */
void zadanie1_5()
{
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;

	if (isBiggest(x1, x2, x3)) cout << x1 << " jest najwieksza";  // TODO wydzielic funkcje
	else if (isBiggest(x2, x1, x3)) cout << x2 << " jest najwieksza";
	else if (isBiggest(x3, x1, x2)) cout << x3 << " jest najwieksza";
	else cout << "Brak liczby najwiekszej";
}

bool isBiggest(int value, int x1, int x2)
{
	return value > x1 && value > x2;
}

/* 1.6. Napisa� prosty kalkulator. Nale�y pobra� od u�ytkownika 2 liczby oraz operator (jeden z czterech: mno�enie, dzielenie, dodawanie,
odejmowanie). Wymagane jest utworzenie prostego menu u�ytkownika. Uwaga - nale�y pami�ta� o u�amkach (1/3 powinno da� 0.33, a nie
0) */
void zadanie1_6()
{
	float x1, x2;
	char op;
	char msgX1[] = "Podaj pierwsza liczbe: ";
	char msgOp[] = "Podaj operator: ";
	char msgX2[] = "Podaj druga liczbe: ";

	x1 = readFloatWithMessage(msgX1);  // TODO wydzielic funkcje ReadFloatWithMessage
	op = readCharWithMessage(msgOp);
	x2 = readFloatWithMessage(msgX2);

	switch (op)
	{
	case '+':
		cout << x1 + x2;
		break;
	case '-':
		cout << x1 - x2;
		break;
	case '*':
		cout << x1 * x2;
		break;
	case '/':
		if (x2 == 0) cout << "Pamietaj cholero, nie dziel przez zero!" << endl;
		else cout << x1 / x2;
		break;
	default: cout << "Nieprawidlowy operator" << endl;
	}
}

float readFloatWithMessage(char msg[])
{
	float x;
	cout << msg;
	cin >> x;
	return x;
}

char readCharWithMessage(char msg[])
{
	char x;
	cout << msg;
	cin >> x;
	return x;
}





/* 2.1. Zapozna� si� z p�tl� while. P�tla ta s�u�y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN� Z G�RY ilo�� razy. P�tla
wykonuje si� zawsze, je�li warunek jest prawdziwy (ewaluowany do true). Napisa� p�tl�, w kt�ej u�ytkownik podaje liczb� x. Nale�y
wy�wietli� t� liczb�. Je�eli u�ytkownik poda 0, nale�y zako�czy� program. */
void zadanie2_1()
{
	int x;  // TODO usunac trik
	do 
	{
		cin >> x;
		cout << x << endl;
	} while (x != 0);
}

void zadanie2_1A()
{
	int x;  // TODO usunac trik
	bool goOn = true;
	while (goOn)
	{
		cin >> x;
		cout << x << endl;
		if (x == 0) goOn = false;
	}
}

/* 2.2. Przerobi� kalkulator z zadania 1.6. Teraz po ka�dym dzia�aniu program powinien spyta� u�ytkownika, czy ten chce powt�rzy�
wszystko od pocz�tku. Je�li tak - restartujemy kalkulator i zaczynamy od nowa. Je�li nie - ko�czymy program. */
void zadanie2_2()
{
	char goOn = 't';

	while (goOn == 't')  // TODO uzyc funkcji z zadania 1.6.
	{
		zadanie1_6();

		cout << "Powtorzyc? (t/n) ";
		cin >> goOn;
	}

}

/* 2.3. Pobra� od u�ytkownika liczb� x. Nale�y wy�wietli� wszystkie kolejne pot�gi liczby x. Zako�czy� program, kiedy liczba przekroczy
100 000. */
void zadanie2_3()
{
	int x, xPow = 1;
	cin >> x;

	while (xPow <= 100000)
	{
		cout << xPow << endl;
		xPow *= x;
	}
}

/* 2.4. Pobra� od u�ytkownika liczb� x. Je�li liczba jest niedodatnia - nale�y zako�czy� program. Nast�pnie nale�y wy�wietla� kolejno (w
nowej linii) wszystkie liczby mniejsze od x, a� osi�gni�te zostanie 0. */
void zadanie2_4()
{
	int x;
	cin >> x;

	while (x > 0)
	{
		x--;
		cout << x << endl;
	}
}

/* 2.5. Zapozna� si� z instrukcjami continue; i break;. Pierwsza s�u�y do zako�czenia iteracji i przej�cia do nast�pnej, a druga natychmiast
ko�czy p�tl�. Przerobi� program z zadania 2.4 (w oryginale: 1.4), aby wy�wietla� tylko parzyste liczby (u�y� if oraz continue). Je�li liczba wynosi 40, nale�y
wyj�� z p�tli i zako�czy� program. */
void zadanie2_5()
{
	int x;
	cin >> x;

	while (x > 0)
	{
		x--;
		if (x % 2 == 1) continue;
		cout << x << endl;
		if (x == 40) break;
	}
}

/* 2.6. Zapozna� si� z p�tl� for. P�tla s�u�y do wykonania danego fragmentu kodu ZNAN� Z G�RY okre�lon� ilo�� razy. Uwaga - ka�d� p�tl�
for mo�na zast�pi� p�tl� while i wzajemnie. Zwyczajowo obowiazuje zasada, �e je�li ilo�� iteracji jest znana - u�ywamy for, a je�li nie jest
znana (zale�y od u�ytkownika lub jakiego� stanu zewn�trznego) - u�ywamy p�tli while. P�tla for sk�ada si� z: ZMIENNEJ ITERACYJNEJ,
czyli stanu pocz�tkowego p�tli, np. int i = 0. Nast�pnie WARUNKU ZAKO�CZENIA P�TLI, np. i<10. Nast�pnie OPERACJI WYKONYWANEJ
PO KA�DEJ ITERACJI - zazwyczaj jest to zwi�kszenie iteratora o 1, czyli i = i + 1, b�d� w skr�cie i++.
Napisa� p�tl� for, kt�ra wy�wietli cyfry od 0 do 9. */
void zadanie2_6()
{
	for (int i = 0; i < 10; i++) cout << i << endl;
}

/* 2.7. Pobra� od u�ytkownika liczby x i y. Zak�adamy, �e y > x (zawsze, nie musimy tego sprawdza�). Za pomoc� p�tli for wypisa� liczby
mi�dzy x a y (do przemy�lenia - co jest stanem pocz�tkowym, a co warunkiem zako�czenia p�tli?) */
void zadanie2_7()
{
	int x, y;
	cin >> x >> y;
	for (int i = x + 1; i < y; i++) cout << i << endl;
}

/* 2.8. Pobra� od u�ytkownika liczb� x. Za pomoc� p�tli for wypisa� wszystkie liczby mniejsze od x, ale wi�ksze ni� 0. */
void zadanie2_8()
{
	int x;
	cin >> x;
	for (int i = x - 1; i > 0; i--) cout << i << endl;
}

/* 2.9. Pobra� od u�ytkownika liczb� x. Za pomoc� p�tli for wypisywa� CO TRZECI� liczb� wi�ksz� od x. P�tla powinna si� zako�czy�, je�li
liczba przekroczy 100. Uwaga - prosz� nie u�ywa� operacji continue i break, a sterowa� tylko parametrami p�tli. */
void zadanie2_9()
{
	int x;
	cin >> x;
	for (int i = x + 3; i <= 100; i += 3) cout << i << endl;
}





/* 3.1. Napisa� metod� void NewLine(). Powinna ona wypisa� na ekran pojedyncz� pust� lini�. U�y� tej metod� w main(). */
void NewLine()
{
	cout << endl;
}

/* 3.2. Napisa� metod� void NewLines(int count). Powinna ona wypisa� tyle nowych linii, ile zosta�o podanych W PARAMETRZE count (nale�y
u�y� p�tli for). U�y� metod� w main() */
void NewLines(int count)
{
	for (int i = 0; i < count; i++) NewLine();
}

/* 3.3. Napisa� metod� void WriteBiggerNumber(int x, int y). Metoda powinna pobra� 2 parametry i zwr�ci� wi�kszy z nich. Wykorzysta�
funckj� w metodzie main(). UWAGA - pobieranie liczb od u�ytkownika powinno odby� si� w funkcji main(), a NIE w WriteBiggerNumber! Do
funkcji nale�y jedynie przes�a� pobrane wcze�niej parametry. */
void WriteBiggerNumber(int x, int y)
{
	if (x > y) cout << x;
	else if (y > x) cout << y;
	else cout << "Brak wiekszej liczby";
}

/* 3.4. Napisa� metod� Multiply(int x, int y) . Metoda powinna ZWR�CI� (s�owo kluczowe return) iloczyn dw�ch parametr�w. Uwaga! Metoda
NIE POWINNA wypisywa� wyniku - powinien on by� wy�wietlony w funkcji main! */
int Multiply(int x, int y)
{
	return x * y;
}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file




/*
Visual Code Studio
printf symbole, mo�liwe wstawienia, wyswietlanie typow danych (int, float, char, string, date, bool)
biblioteka do matematyki

jesli starczy czasu poczytac o plikach naglowkowych, wydzielic grupy zadan do osobnych plikow ale wywolywac z jednego pliku
uruchomic biblioteke openGL w C++; przejsc tutorial z openGL
poczytac o blender - program do modelowania 3d
zobaczyc portal: Pasja Informatyki (youtube), Deweloper Wannabe, Hello Roman
zobaczyc j�zyk programowania Rust
*/