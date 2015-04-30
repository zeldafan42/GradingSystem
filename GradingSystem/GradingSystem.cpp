/*
 * GradingSystem.cpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#include <iostream>
#include "Person.hpp"
#include "Course.hpp"
#include "Teacher.hpp"
#include "Student.hpp"
#include "GradedCourse.hpp"
#include <forward_list>
#include <map>


using namespace std;

int main()
{
	int menuChoice = 0;
	int studentOrTeacher = 0;

	string name = "";

	map<string,Student*> studentTable;
	map<string,Teacher*> teacherTable;
	map<string,Course*> courseTable;

	while(true)
	{
		printMenu();
		cin >> menuChoice;

		if(menuChoice>0 && menuChoice<5)
		{
			if(menuChoice == 1)
			{
				studentOrTeacher = addPerson();

				if(studentOrTeacher==1)
				{
					name = readName();

					studentTable.insert(pair<string,Student*>(name,Student(name)));
					continue;
				}
				else if(studentOrTeacher == 2)
				{
					name = readName();
					Teacher* currentTeacher = new Teacher(name);
					Course* currentCourse;

					teacherTable.insert(pair<string,Teacher*>(name,currentTeacher));

					while(true)
					{
						name = readName();

						if(name != "0")
						{
							currentCourse = new Course(name);
							currentTeacher->addCourse(currentCourse);
							courseTable.insert(pair<string,Course*>(name,currentCourse));
						}
					}

					continue;
				}
				else
				{
					cerr << "Error: function addPerson() did not return 1 or 2" << endl;
					continue;
				}
			}
			else if(menuChoice == 2)
			{


				studentOrTeacher = findPerson();

				if(studentOrTeacher==1)
				{
					name = readName();
					studentTable.find(name);
					continue;
				}
				else if(studentOrTeacher == 2)
				{
					name = readName();

					teacherTable.find(name);
					continue;
				}
				else
				{
					cerr << "Error: function findPerson() did not return 1 or 2" << endl;
					continue;
				}
			}
			else if(menuChoice == 3)
			{
				cout << "--------------------------------------------" << endl;
				cout << "                TEACHER LIST" << endl;
				printTable(&teacherTable);
				cout << "--------------------------------------------" << endl;
				cout << "                STUDENT LIST" << endl;
				printTable(&studentTable);

			}


		}
		else
		{
			if(menuChoice == 5)
			{
				break;
			}
			else
			{
				cout << "Wrong input!\nPlease select an option from 1 to 5" << endl;
			}
		}
	}



	return 0;
}


void printMenu()
{
	cout << "1. Add person\n2. Find person\n3. Show people\n4. Grade student\n5. Quit\n> " << endl;
}

int addPerson()
{
	int input = 0;

	cout << "1. Add student\n2. Add teacher" << endl << "> ";
	cin >> input;

	while(input!=1 && input!=2)
	{
		cout << "Wrong input!\nPlease select an option from 1 to 2" << endl;
		cout << "1. Add student\n2. Add teacher" << endl << "> ";
		cin >> input;
	}

	return input;
}

int findPerson()
{
	int input = 0;

	cout << "1. Find student\n2. Find teacher" << endl << "> ";
	cin >> input;

	while(input!=1 && input!=2)
	{
		cout << "Wrong input!\nPlease select an option from 1 to 2" << endl;
		cout << "1. Find student\n2. Find teacher" << endl << "> ";
		cin >> input;
	}

	return input;
}

string readName()
{
	string name = "";
	cout << "Please enter the name: " << endl << "> ";
	cin >> name;

	while(name=="")
	{
		cout << "Wrong input!\nPlease enter the name: " << endl << "> ";
		cin >> name;
	}

	return name;
}

void printTable(map<string,Student*>* table)
{
	for(auto it = (*table).begin();it != (*table).end(); ++it)
	{
		it->second->printPerson();
	}
}

void printTable(map<string,Teacher*>* table)
{
	for(auto it = (*table).begin();it != (*table).end(); ++it)
	{
		it->second->printPerson();
	}
}
