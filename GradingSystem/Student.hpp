/*
 * Student.hpp
 *
 *  Created on: 30.04.2015
 *      Author: Christine
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Person.hpp"

class Student: public Person {
public:
	Student(const string &name);
	virtual ~Student();
};

#endif /* STUDENT_HPP_ */
