/*
 * Teacher.cpp
 *
 *  Created on: 24.04.2015
 *      Author: Christine
 */

#include "Teacher.hpp"
#include <iostream>

using namespace std;

Teacher::Teacher(const string &name) : Person(name)
{
}

void Teacher::printPerson() const
{
	cout << name << " (Teacher: ";
	auto it = courses.begin();
	(*it)->printCourse();
	++it;
	for (; it != courses.end(); ++it )
	{
		cout  << ", ";
		(*it)->printCourse();
	}

}

void Teacher::addCourse(const Course * course)
{
	courses.push_front(course);

}


Teacher::~Teacher()
{
}


