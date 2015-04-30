/*
 * Student.hpp
 *
 *  Created on: 30.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Person.hpp"
#include "GradedCourse.hpp"
#include <forward_list>

class Student: public Person
{
	public:
	Student(const string &name);
	virtual ~Student();
	void printPerson() const;
	void addGradedCourse(GradedCourse * course);
	bool hasCourse(const Course * course) const;
	void updateGrade(const Course * course, int grade);

	private:
	forward_list<GradedCourse*> courses;
};

#endif /* STUDENT_HPP_ */
