// C_zadania_3_github.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct Student
{
	int Age;
	int Height;
	int Semester;
};

Student *create(int, int, int);
void printStudent(Student *);
bool areEqual(Student *, Student *);
void zadanie1_2();

int main()
{
	/* Student *s1 = create(29, 179, 99);
	Student *s2 = create(29, 179, 99);
	cout << areEqual(s1, s2);
	free(s1);
	free(s2); */

	zadanie1_2();
}

/* 1.1. Utworzyc strukture Student taka jak powyzej. Napisac metody:
Student* Create(int age, int height, int semester)  // alokuje pamiec i tworzy studenta o podanych parametrach. WAZNE - pamiec nalezy
potem zwolnic w main()!
void PrintStudent(Student *s)  // wypisuje wszystkie skladowe struktury
bool AreEqual(Student* s1, Student* s2)  // zwraca informacje, czy skladowe sa takie same */
Student *create(int age, int height, int semester)
{
	Student *s = (Student*)malloc(sizeof(Student));
	s->Age = age;
	s->Height = height;
	s->Semester = semester;

	return s;
}

void printStudent(Student *s)
{
	cout << "Age: " << s->Age << endl;
	cout << "Height: " << s->Height << endl;
	cout << "Semester: " << s->Semester << endl;
}

bool areEqual(Student *s1, Student *s2)
{
	if (s1->Age == s2->Age && s1->Height == s2->Height && s1->Semester == s2->Semester) return true;
	else return false;
}

/* 1.2. Utworzyc tablice 3 studentow. Zapelnic ja wartosciami, wyswietlic, zwolnic pamiec. Tablica powinna byc utworzona za pomoca
metody malloc (prosze pilnowac odpowiedniej ilosci gwiazdek!) */
void zadanie1_2()
{
	int length = 3;
	Student **studArr = (Student**)malloc(sizeof(Student) * length);
	studArr[0] = create(22, 183, 3);
	studArr[1] = create(24, 169, 5);
	studArr[2] = create(5, 78, 10);

	for (int i = 0; i < length; i++)
	{
		cout << "Student " << i << endl;
		printStudent(studArr[i]);
		free(studArr[i]);
	}
	
	free(studArr);
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
