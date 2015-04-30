/*
 * GradedCourse.cpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#define MAX_GRADE 5
#define MIN_GRADE 1

#include "GradedCourse.hpp"
#include <iostream>

using namespace std;

GradedCourse::GradedCourse(Course * course, int grade)
{
	this->grade = grade;
	this->course = course;
}

void GradedCourse::printCourse() const
{
	course->printCourse();
	cout << ": " << grade;
}

bool GradedCourse::isCourse(const Course * course) const
{
	return course == this->course;
}

void GradedCourse::gradeStudent(int grade)
{

	if(grade<=MAX_GRADE && grade >= MIN_GRADE)
	{
		cout << "Changing grade from " << this->grade << " to " << grade << "!" << endl;
		this->grade = grade;
	}
	else
	{
		cerr << "Grade out of bounds!" << endl;
	}
}
