/*
 * Course.cpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen and Arthur Bouz
 */

#include <iostream>
#include "Course.hpp"

using namespace std;

Course::Course(string name)
{
	this->name = name;
}

void Course::printCourse() const
{
	cout << name;
}

