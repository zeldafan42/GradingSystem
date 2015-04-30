/*
 * Student.cpp
 *
 *  Created on: 30.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#include "Student.hpp"


Student::Student(const string &name) : Person(name)
{
}

void Student::printPerson() const
{
	cout << name << " (Student";
	if(!courses.empty())
	{
		cout << ": ";
		auto it = courses.begin();
		(*it)->printCourse();
		++it;
		for (; it != courses.end(); ++it )
		{
			cout  << ", ";
			(*it)->printCourse();
		}
	}
	cout << ")" << endl;
}

void Student::addGradedCourse(const GradedCourse * course)
{
	courses.push_front(course);
}

Student::~Student()
{
}

