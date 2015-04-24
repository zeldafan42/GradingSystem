/*
 * GradedCourse.cpp
 *
 *  Created on: 24.04.2015
 *      Author: Christine
 */

#define MAX_GRADE 5
#define MIN_GRADE 1

#include "GradedCourse.hpp"
#include <iostream>

using namespace std;

GradedCourse::GradedCourse(int grade, Course * course)
{
	this->grade = grade;
	this->course = course;
}

void GradedCourse::printCourse() const
{
	course->printCourse();
	cout << ": " << grade;
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
