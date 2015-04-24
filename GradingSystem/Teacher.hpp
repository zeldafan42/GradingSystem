/*
 * Teacher.hpp
 *
 *  Created on: 24.04.2015
 *      Author: Christine
 */

#ifndef TEACHER_HPP_
#define TEACHER_HPP_
#include <forward_list>
#include "Person.hpp"
#include "Course.hpp"

using namespace std;

class Teacher : public Person
{
	public:
		Teacher(string name);
		virtual ~Teacher();
		void printPerson() const;
		void addCourse(const Course * course);
	private:
		forward_list<const Course*> courses;
};


#endif /* TEACHER_HPP_ */
