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
int getPersonOption(string action);
int getNumber();
string readName(string specific);
int readGrade();
void printTable(map<string,Student*>* table);
void printTable(map<string,Teacher*>* table);


int main()
{
	int menuChoice = 0;
	int studentOrTeacher = 0;
	int currentGrade = 0;

	string name = "";
	Teacher* currentTeacher;
	Course* currentCourse;
	Student* currentStudent;
	GradedCourse* currentGradedCourse;

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
					studentOrTeacher = getPersonOption("Add");

					if(studentOrTeacher==1)
					{
						name = readName("student");
						currentStudent = new Student(name);

						studentTable.insert(pair<string,Student*>(name,currentStudent));
						break;
					}
					else if(studentOrTeacher == 2)
					{
						name = readName("teacher");
						currentTeacher = new Teacher(name);

						teacherTable.insert(pair<string,Teacher*>(name,currentTeacher));

						while(true)
						{
							name = readName("course");

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
					studentOrTeacher = getPersonOption("Find");

					if(studentOrTeacher==1)
					{
						name = readName("student");
						studentTable.find(name);
						break;
					}
					else if(studentOrTeacher == 2)
					{
						name = readName("teacher");

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

					if(it1 == studentTable.end())
					{
						cout << "Could not find student!" << endl;
						break;
					}

					currentStudent = it1->second;


					name = readName("course");
					auto it2 = courseTable.find(name);
					if(it2 == courseTable.end())
					{
						cout << "Could not find course!" << endl;
						break;
					}
					currentCourse = it2->second;

					currentGrade = readGrade();

					currentGradedCourse = new GradedCourse(currentCourse,currentGrade);

					currentStudent->addGradedCourse(currentGradedCourse);

					break;
				}

			case 5:
				{
					for(auto it = studentTable.begin(); it != studentTable.end(); ++it)
					{
						delete it->second;
					}
					for(auto it = teacherTable.begin(); it != teacherTable.end(); ++it)
					{
						delete it->second;
					}
					for(auto it = courseTable.begin(); it != courseTable.end(); ++it)
					{
						delete it->second;
					}
					return 0;
				}

			default:
					cout << "Wrong input!" << endl <<"Please select an option from 1 to 5" << endl;
					break;
		}
	}

	return 0;
}


void printMenu()
{
	cout << "1. Add person" << endl << "2. Find person" << endl << "3. Show people" << endl << "4. Grade student" << endl << "5. Quit" << endl <<"> " << endl;
}

int getPersonOption(string action)
{
	int input = 0;

	cout << "1. " << action << " student" << endl << "2. " << action << " teacher" << endl << "> ";
	input  = getNumber();

	while(input!=1 && input!=2)
	{
		cout << "Wrong input!" << endl << "Please select an option from 1 to 2" << endl;
		cout << "1. " << action << " student" << endl << "2. " << action << " teacher" << endl << "> ";
		input  = getNumber();
	}

	return input;
}

string readName(string specific)
{
	string name = "";
	cout << "Please enter the name of the " << specific << ": " << endl << "> ";
	cin >> name;

	while(name == "")
	{
		cout << "Wrong input!" << endl << "Please enter the name of the " << specific << ": " << endl << "> ";
		cin >> name;
	}

	return name;
}

int readGrade()
{
	int grade = 0;
	cout << "Please enter the grade: " << endl << "> ";
	grade = getNumber();

	return grade;
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
	    cout << "Invalid input; please re-enter." << endl;
	}
	return num;
}
