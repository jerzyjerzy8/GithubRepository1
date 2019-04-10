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
void zadanie1_6();

void zadanie2_1();
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

/* 1.1. Zadeklarowaæ zmienne typu int, float, char. Przypisaæ do nich wartoœæ, wyœwietliæ je na ekran. */
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

/* 1.2. Wyœwietliæ zmienn¹ typu int na ekran. Nale¿y u¿yæ metody printf i konstrukcji %d */
void zadanie1_2()
{
	int myVariable = 1;
	printf("%d", myVariable);
}

/* 1.3. Pobraæ od u¿ytkownika liczbê x. Wyœwietliæ kwadrat liczby x. */
void zadanie1_3()
{
	int x;
	cin >> x;
	cout << x * x;
}

/* 1.4. Zapoznaæ siê z instrukcjami warunkowymi (if, else if, else oraz switch). Pobraæ od u¿ywkownika liczbê i wyœwietliæ informacjê, czy jest
ona: mniejsza, wiêksza, czy równa 0. */
void zadanie1_4()
{
	int x;
	cin >> x;

	if (x > 0) cout << "x > 0";
	else if (x == 0) cout << "x = 0";
	else cout << "x < 0";
}

/* 1.5. Pobraæ ud u¿ytkownika 3 liczby (x1, x2, x3). Wyœwietliæ informacjê, która z tych liczb jest najwiêksza. */
void zadanie1_5()
{
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;

	if (x1 > x2 && x1 > x3) cout << x1 << " jest najwieksza";
	else if (x2 > x1 && x2 > x3) cout << x2 << " jest najwieksza";
	else if (x3 > x1 && x3 > x2) cout << x3 << " jest najwieksza";
	else cout << "Brak liczby najwiekszej";
}

/* 1.6. Napisaæ prosty kalkulator. Nale¿y pobraæ od u¿ytkownika 2 liczby oraz operator (jeden z czterech: mno¿enie, dzielenie, dodawanie,
odejmowanie). Wymagane jest utworzenie prostego menu u¿ytkownika. Uwaga - nale¿y pamiêtaæ o u³amkach (1/3 powinno daæ 0.33, a nie
0) */
void zadanie1_6()
{
	float x1, x2;
	char op;

	cout << "Podaj pierwsza liczbe: ";
	cin >> x1;
	cout << "Podaj operator: ";
	cin >> op;
	cout << "Podaj druga liczbe: ";
	cin >> x2;

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
		if (x2 == 0) cout << "Pamietaj cholero, nie dziel przez zero!";
		else cout << x1 / x2;
		break;
	default: cout << "Nieprawidlowy operator";
	}
}





/* 2.1. Zapoznaæ siê z pêtl¹ while. Pêtla ta s³u¿y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN¥ Z GÓRY iloœæ razy. Pêtla
wykonuje siê zawsze, jeœli warunek jest prawdziwy (ewaluowany do true). Napisaæ pêtlê, w któej u¿ytkownik podaje liczbê x. Nale¿y
wyœwietliæ tê liczbê. Je¿eli u¿ytkownik poda 0, nale¿y zakoñczyæ program. */
void zadanie2_1()
{
	int x = 1;
	while (x != 0)
	{
		cin >> x;
		cout << x << endl;
	}
}

/* 2.2. Przerobiæ kalkulator z zadania 1.6. Teraz po ka¿dym dzia³aniu program powinien spytaæ u¿ytkownika, czy ten chce powtórzyæ
wszystko od pocz¹tku. Jeœli tak - restartujemy kalkulator i zaczynamy od nowa. Jeœli nie - koñczymy program. */
void zadanie2_2()
{
	float x1, x2;
	char op;
	char goOn = 't';

	while (goOn == 't')
	{
		cout << "Podaj pierwsza liczbe: ";
		cin >> x1;
		cout << "Podaj operator: ";
		cin >> op;
		cout << "Podaj druga liczbe: ";
		cin >> x2;

		if (op == '+') cout << x1 + x2 << endl;
		else if (op == '-') cout << x1 - x2 << endl;
		else if (op == '*') cout << x1 * x2 << endl;
		else if (op == '/')
		{
			if (x2 == 0) cout << "Pamietaj cholero, nie dziel przez zero!" << endl;
			else cout << x1 / x2 << endl;
		}
		else cout << "Nieprawidlowy operator" << endl;

		cout << "Powtorzyc? (t/n) ";
		cin >> goOn;
	}

}

/* 2.3. Pobraæ od u¿ytkownika liczbê x. Nale¿y wyœwietliæ wszystkie kolejne potêgi liczby x. Zakoñczyæ program, kiedy liczba przekroczy
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

/* 2.4. Pobraæ od u¿ytkownika liczbê x. Jeœli liczba jest niedodatnia - nale¿y zakoñczyæ program. Nastêpnie nale¿y wyœwietlaæ kolejno (w
nowej linii) wszystkie liczby mniejsze od x, a¿ osi¹gniête zostanie 0. */
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

/* 2.5. Zapoznaæ siê z instrukcjami continue; i break;. Pierwsza s³u¿y do zakoñczenia iteracji i przejœcia do nastêpnej, a druga natychmiast
koñczy pêtlê. Przerobiæ program z zadania 2.4 (w oryginale: 1.4), aby wyœwietla³ tylko parzyste liczby (u¿yæ if oraz continue). Jeœli liczba wynosi 40, nale¿y
wyjœæ z pêtli i zakoñczyæ program. */
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

/* 2.6. Zapoznaæ siê z pêtl¹ for. Pêtla s³u¿y do wykonania danego fragmentu kodu ZNAN¥ Z GÓRY okreœlon¹ iloœæ razy. Uwaga - ka¿d¹ pêtlê
for mo¿na zast¹piæ pêtl¹ while i wzajemnie. Zwyczajowo obowiazuje zasada, ¿e jeœli iloœæ iteracji jest znana - u¿ywamy for, a jeœli nie jest
znana (zale¿y od u¿ytkownika lub jakiegoœ stanu zewnêtrznego) - u¿ywamy pêtli while. Pêtla for sk³ada siê z: ZMIENNEJ ITERACYJNEJ,
czyli stanu pocz¹tkowego pêtli, np. int i = 0. Nastêpnie WARUNKU ZAKOÑCZENIA PÊTLI, np. i<10. Nastêpnie OPERACJI WYKONYWANEJ
PO KA¯DEJ ITERACJI - zazwyczaj jest to zwiêkszenie iteratora o 1, czyli i = i + 1, b¹dŸ w skrócie i++.
Napisaæ pêtlê for, która wyœwietli cyfry od 0 do 9. */
void zadanie2_6()
{
	for (int i = 0; i < 10; i++) cout << i << endl;
}

/* 2.7. Pobraæ od u¿ytkownika liczby x i y. Zak³adamy, ¿e y > x (zawsze, nie musimy tego sprawdzaæ). Za pomoc¹ pêtli for wypisaæ liczby
miêdzy x a y (do przemyœlenia - co jest stanem pocz¹tkowym, a co warunkiem zakoñczenia pêtli?) */
void zadanie2_7()
{
	int x, y;
	cin >> x >> y;
	for (int i = x + 1; i < y; i++) cout << i << endl;
}

/* 2.8. Pobraæ od u¿ytkownika liczbê x. Za pomoc¹ pêtli for wypisaæ wszystkie liczby mniejsze od x, ale wiêksze ni¿ 0. */
void zadanie2_8()
{
	int x;
	cin >> x;
	for (int i = x - 1; i > 0; i--) cout << i << endl;
}

/* 2.9. Pobraæ od u¿ytkownika liczbê x. Za pomoc¹ pêtli for wypisywaæ CO TRZECI¥ liczbê wiêksz¹ od x. Pêtla powinna siê zakoñczyæ, jeœli
liczba przekroczy 100. Uwaga - proszê nie u¿ywaæ operacji continue i break, a sterowaæ tylko parametrami pêtli. */
void zadanie2_9()
{
	int x;
	cin >> x;
	for (int i = x + 3; i <= 100; i += 3) cout << i << endl;
}





/* 3.1. Napisaæ metodê void NewLine(). Powinna ona wypisaæ na ekran pojedyncz¹ pust¹ liniê. U¿yæ tej metodê w main(). */
void NewLine()
{
	cout << endl;
}

/* 3.2. Napisaæ metodê void NewLines(int count). Powinna ona wypisaæ tyle nowych linii, ile zosta³o podanych W PARAMETRZE count (nale¿y
u¿yæ pêtli for). U¿yæ metodê w main() */
void NewLines(int count)
{
	for (int i = 0; i < count; i++) NewLine();
}

/* 3.3. Napisaæ metodê void WriteBiggerNumber(int x, int y). Metoda powinna pobraæ 2 parametry i zwróciæ wiêkszy z nich. Wykorzystaæ
funckjê w metodzie main(). UWAGA - pobieranie liczb od u¿ytkownika powinno odbyæ siê w funkcji main(), a NIE w WriteBiggerNumber! Do
funkcji nale¿y jedynie przes³aæ pobrane wczeœniej parametry. */
void WriteBiggerNumber(int x, int y)
{
	if (x > y) cout << x;
	else if (y > x) cout << y;
	else cout << "Brak wiekszej liczby";
}

/* 3.4. Napisaæ metodê Multiply(int x, int y) . Metoda powinna ZWRÓCIÆ (s³owo kluczowe return) iloczyn dwóch parametrów. Uwaga! Metoda
NIE POWINNA wypisywaæ wyniku - powinien on byæ wyœwietlony w funkcji main! */
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
