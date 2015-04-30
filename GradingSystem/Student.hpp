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
	void addGradedCourse(const GradedCourse * course);

	private:
	forward_list<const GradedCourse*> courses;
};

#endif /* STUDENT_HPP_ */
