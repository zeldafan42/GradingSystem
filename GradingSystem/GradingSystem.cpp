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
#include <limits>


using namespace std;

void printMenu();
int addPerson();
int findPerson();
int getNumber();
string readName();
string readName(string specific);
void printTable(map<string,Student*>* table);
void printTable(map<string,Teacher*>* table);


int main()
{
	int menuChoice = 0;
	int studentOrTeacher = 0;

	string name = "";
	Teacher* currentTeacher;
	Course* currentCourse;
	Student* currentStudent;

	map<string,Student*> studentTable;
	map<string,Teacher*> teacherTable;
	map<string,Course*> courseTable;

	while(true)
	{
		printMenu();
		menuChoice = getNumber();

		switch(menuChoice)
		{	case 1:
			{
					studentOrTeacher = person("Add");

					if(studentOrTeacher==1)
					{
						name = readName();
						currentStudent = new Student(name);

						studentTable.insert(pair<string,Student*>(name,currentStudent));
						break;
					}
					else if(studentOrTeacher == 2)
					{
						name = readName();
						currentTeacher = new Teacher(name);

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
							else
							{
								break;
							}
						}

						break;
					}
					else
					{
						cerr << "Error: function addPerson() did not return 1 or 2" << endl;
						break;
					}
			}

			case 2:
				{
					studentOrTeacher = person("Find");

					if(studentOrTeacher==1)
					{
						name = readName();
						studentTable.find(name);
						break;
					}
					else if(studentOrTeacher == 2)
					{
						name = readName();

						teacherTable.find(name);
						break;
					}
					else
					{
						cerr << "Error: function findPerson() did not return 1 or 2" << endl;
						break;
					}
				}
			case 3:
				{
					cout << "--------------------------------------------" << endl;
					cout << "                TEACHER LIST" << endl;
					printTable(&teacherTable);
					cout << "--------------------------------------------" << endl;
					cout << "                STUDENT LIST" << endl;
					printTable(&studentTable);
					break;
				}
			case 4:
				{
					name = readName("student");
					auto it1 = studentTable.find(name);

					currentStudent = it1->second;

					name = readName("course");
					auto it2 = courseTable.find(name);
					currentCourse = it2->second;
					break;
				}

			case 5:
				{
					return 0;
				}

			default:
					cout << "Wrong input!\nPlease select an option from 1 to 5" << endl;
					break;
		}
	}

	return 0;
}


void printMenu()
{
	cout << "1. Add person\n2. Find person\n3. Show people\n4. Grade student\n5. Quit\n> " << endl;
}

int person(string action)
{
	int input = 0;

	cout << "1. " << action << " student\n2. " << action << " teacher" << endl << "> ";
	input  = getNumber();

	while(input!=1 && input!=2)
	{
		cout << "Wrong input!\nPlease select an option from 1 to 2" << endl;
		cout << "1. " << action << " student\n2. " << action << " teacher" << endl << "> ";
		input  = getNumber();
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

string readName(string specific)
{
	string name = "";
	cout << "Please enter the name of the " << specific << ": " << endl << "> ";
	cin >> name;

	while(name=="")
	{
		cout << "Wrong input!\nPlease enter the name of the " << specific << ": " << endl << "> ";
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

int getNumber()
{
	int num = 0;
	while (!(cin >> num))
	{
	    cin.clear(); //clear bad input flag
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	    cout << "Invalid input; please re-enter.\n";
	}
	return num;
}
