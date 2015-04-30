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

bool Student::hasCourse(const Course * course) const
{
	bool found = false;
	for(auto it = courses.begin(); it != courses.end(); ++it)
	{
		if((*it)->isCourse(course))
		{
			found = true;
		}
	}
	return found;
}

void Student::updateGrade(const Course * course, int grade)
{
	for(auto it = courses.begin(); it != courses.end(); ++it)
	{
		if((*it)->isCourse(course))
		{
			(*it)->gradeStudent(grade);
		}
	}
}

void Student::addGradedCourse(GradedCourse * course)
{
	courses.push_front(course);
}

Student::~Student()
{
	while(!courses.empty())
	{
		delete courses.front();
		courses.pop_front();
	}
}

