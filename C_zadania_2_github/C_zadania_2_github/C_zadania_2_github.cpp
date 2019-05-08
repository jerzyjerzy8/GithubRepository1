// C_zadania_2_github.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <regex>
#include <tuple>
using namespace std;

int *zadanie1_1();
void zadanie1_2(int *, int );
void printForward(int *, int);
bool zadanie1_3(int *, int);

bool isSorted(int *, int);
void printBackwards(int *, int);
void printDots(int *, int);
void printLineOfDots(int);
int sum(int *, int);
void Sort(int *, int);
void mySwap(int *, int, int);

int getLength(char *);
void reverse(char *);
bool containsDigits(char *);
bool isADigit(char);
bool containsDigitsReg(char *);
void zadanie3_4();

void zadanie4_1();
tuple<int*, int> getArrayAndItsSizeFromUser();
void zadanie4_2();
bool areArraysIdentical(int *, int, int *, int);
void zadanie4_4();
char *reverseString(char *);

int main()
{
	//int myArr[] = { 1, 3, 4, 2 };
	//int myArr2[] = { 1, 3, 4, 3 };
	
	//int *myArr2 = zadanie1_1();
	//zadanie1_2(myArr2, 5);

	//cout << zadanie1_3(myArr, 4);

	//printBackwards(myArr, 4);

	//printDots(myArr, 4);

	//cout << sum(myArr, 4);

	//printForward(myArr, 4);
	//Sort(myArr, 4);
	//mySwap(myArr, 0, 3);
	//printForward(myArr, 4);

	char str[] = "lolek";

	//cout << getLength(str);

	//reverse(str);

	//cout << containsDigits(str);

	//cout << areArraysIdentical(myArr, 4, myArr2, 4);

	cout << reverseString(str);

	//zadanie4_4();
}

/* 1.1. Utworzyc 5-cio elementowa tablice typu int. Pobrac od uzytkownika 5 elementow i dodac je do tablicy. Nastepnie
wyswietlic najwieksza liczbe z tablicy (algorytm do samodzielnej implementacji) */
int *zadanie1_1()
{
	static int arr[5];
	int max;

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		if (i == 0) max = arr[i];
		else if (arr[i] > max) max = arr[i];
	}

	cout << max << endl;

	return arr;
}


/* 1.2 Wyswietlic w petli tablice z zadania 1.1. od poczatku i od konca (dwie petle) */
void zadanie1_2(int *a, int s)
{
	printForward(a, s);

	printBackwards(a, s);
}

void printForward(int *a, int s)
{
	for (int i = 0; i < s; i++) cout << a[i] << endl;
}

/* 1.3. Napisac algorytm sprawdzajacy, czy tablica jest posortowana w kolejnosci niemalejacej */
bool zadanie1_3(int *a, int s)
{
	for (int i = 0; i < s - 1; i++) if (a[i + 1] < a[i]) return false;
	return true;
}





/* 2.1. Utworzyc osobna metode bool IsSorted(int *, int) realizujaca zadanie 1.3. (UWAGA - w jezyku C niedostepny jest typ bool
z wartosciami true i false, zamiast niego nalezy uzyc int i wartosci 1 i 0 */
bool isSorted(int *a, int s)
{
	return zadanie1_3(a, s);
}

/* 2.2. Utworzyc metode void printBackwards(int *a, int s) sluzaca do wypisania tablicy OD KONCA */
void printBackwards(int *a, int s)
{
	for (int i = s - 1; i >= 0; i--) cout << *(a + i) << endl;
}

/* 2.3. Utworzyc metode printDots(int *a, int s) wyswietlajaca w nowych liniach tyle kropek, ile znajduje sie w danym
elemencie tablicy. Dla przykladu, dla tablicy: int tab[] = {3,2,5,4}; wynik powinien byc nastepujacy:
...
..
.....
.... */
void printDots(int *a, int s)
{
	for (int i = 0; i < s; i++) printLineOfDots(a[i]);
}

void printLineOfDots(int n)
{
	for (int i = 0; i < n; i++) cout << '.';
	cout << endl;
}

/* 2.4. Utworzyc metode int Sum(int *a, int s) liczaca sume elementow tablicy. */
int sum(int *a, int s)
{
	int sum = 0;
	for (int i = 0; i < s; i++) sum += a[i];
	return sum;
}

/* 2.5. Zaimplementowac algorytm sortowania babelkowego (w funkcji main(), nie ma potrzeby tworzenia dodatkowej funkcji).
Algorytm powinien posortowac dowolnie duza tablice w kolejnosci niemalejacej */
void Sort(int *a, int s)
{
	int unsorted = s;
	int buffer;
	//printForward(a, s);
	while (unsorted > 0)
	{
		for (int i = 0; i < unsorted - 1; i++)
		{
			if (*(a + i + 1) < *(a + i))
			{
				mySwap(a, i, i + 1);
			}
			/*if (a[i + 1] < a[i])
			{
				buffer = a[i + 1];
				a[i + 1] = a[i];
				a[i] = buffer;
			}*/
		}
		//printForward(a, s);
		unsorted--;
	}
}

void mySwap(int *arr, int i, int j)
{
	int buffer = *(arr + j);
	*(arr + j) = *(arr + i);
	*(arr + i) = buffer;
}




/* 3.1. Napisac metode int getLength(char *str), w ktorej WLASNORECZNIE (nie wolno korzystac z metody strlen()) przeliczony zostanie rozmiar
lancucha (bez null-terminatora). Dla przykladu dla "Hello!" wynik powinien wynosic 6. */
int getLength(char *str)
{
	int length = 0;

	for (int i = 0; true; i++)
	{
		if (str[i] == '\0') break;
		length++;
	}

	return length;
}

/* 3.2. Napisac metode void Reverse(char *str), ktora wypisze lancuch znakow od konca (zakaz uzywania strlen, mozna
uzyc metode z zadania 3.1.) */
void reverse(char *str)
{
	for (int i = getLength(str) - 1; i >= 0; i--) cout << str[i];
	cout << endl;
}

/* 3.3. Napisac metode bool containsDigits(char *str), ktora zwroci informacje, czy w danym stringu znajduje sie jakakolwiek cyfra.
Dla przykladu: "asdfgzxcv" -> false, "asdf5asdf" -> true */
bool containsDigits(char *str)
{
	for (int i = 0; true; i++)
	{
		if (str[i] == '\0') break;
		if (isADigit(str[i])) return true;
	}
	return false;
}

bool isADigit(char ch)
{
	char digits[] = "0123456789";
	for (int i = 0; true; i++)
	{
		if (digits[i] == '\0') break;
		if (ch == digits[i]) return true;
	}
	return false;
}

bool containsDigitsReg(char *str)
{
	regex reg("[0-9]");
	return regex_search(str, reg);
}

/* 3.4. Pobrac od uzytkownika lancuch znakow (dowolna metoda). Przekazac go do kazdej z metod z 3. czesci zadan. */
void zadanie3_4()
{
	char str[20];
	cin >> str;

	cout << "getLength: " << getLength(str) << endl;
	cout << "reverse: ";
	reverse(str);
	cout << "containsDigits: " << containsDigits(str) << endl;
}





/* 4.1. Pobrac od uzytkownika liczbe n. Zaalokowac pamiec na n elementow int i pobrac je od uzytkownika. Wykonac na niej
metode printBackwards z 2.2. */
void zadanie4_1()
{
	tuple<int*, int> t = getArrayAndItsSizeFromUser();
	int *arr = get<0>(t);
	int n = get<1>(t);

	printBackwards(arr, n);
}

tuple<int*, int> getArrayAndItsSizeFromUser()
{
	int n;
	cin >> n;

	int *arr;
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	tuple<int*, int> t = make_tuple(arr, n);
	return t;
}

/* 4.2. Pobrac od uzytkownika liczbe n. Zaalokowac pamiec na n elementow int i pobrac je od uzytkownika. Nastepnie zaalokowac
pamiec i utworzyc tablice, w ktorej beda tylko UJEMNE wartosci z pierwszej tablicy. Na koniec zwolnic pamiec na obie tablice. */
void zadanie4_2()
{
	tuple<int*, int> t = getArrayAndItsSizeFromUser();
	int *arr = get<0>(t);
	int n = get<1>(t);

	int count = 0;
	for (int i = 0; i < n; i++) if (arr[i] < 0) count++;

	int *arr2;
	arr2 = (int*)malloc(sizeof(int) * count);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			arr2[j] = arr[i];
			j++;
		}
	}

	printForward(arr2, j);
	free(arr);
	free(arr2);
}

/* 4.3. Napisac metode bool AreArraysIdentical(int *a1, int s1, int *a2, int s2) zwracajaca informacje, czy dwie tablice podane
jako parametr sa identyczne, tj. czy maja taka sama dlugosc i czy na kazdym indeksie wystepuje taki sam element. */
bool areArraysIdentical(int *a1, int s1, int *a2, int s2)
{
	if (s1 != s2) return false;
	for (int i = 0; i < s1; i++)
	{
		if (a1[i] != a2[i]) return false;
	}
	return true;
}

/* 4.4. Napisac metode char *reverseString(char *str), ktora ZWROCI (a nie wypisze!) string, ktory jest odwroconym stringiem przekazanym
jako pierwszy parametr. Funkcja zaalokuje pamiec na nowy lancuch i go zwroci. Ca³y algorytm nalezy zaimplementowac samodzielnie.
Nalezy go nastepnie "przechwycic" w funkcji main, aby pamiec na koniec wyczyscic:
int main()
{
	// zaalokuj i pobierz od usera tablice *str
	char *result = reverseString(str);
	printf("%s", result);
	free(str);   // zwalniamy pamiec z pierwszej tablicy
	free(result);   // zwracamy wynik z funkcji, ktory "przechwycil" main()
} */
void zadanie4_4()
{
	int n;
	cin >> n;
	char *str = (char*)malloc(sizeof(char) * n);
	cin >> str;

	char *result = reverseString(str);
	cout << result;
	
	free(str);
	free(result);
}

char *reverseString(char *str)
{
	int length = getLength(str);
	char *str2 = (char*)malloc(sizeof(char) * (length + 1));
	
	for (int i = 0, j = length - 1; i < length; i++, j--) str2[i] = str[j];
	str2[length] = '\0';

	return str2;
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
