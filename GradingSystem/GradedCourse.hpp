/*
 * GradedCourse.hpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef GRADEDCOURSE_HPP_
#define GRADEDCOURSE_HPP_

#include "Course.hpp"

class GradedCourse
{
public:
	void printCourse() const;
	GradedCourse(Course * course, int grade);
	void gradeStudent(int grade);
	bool isCourse(const Course * course) const;

private:
	int grade;
	Course * course;

};
#endif /* GRADEDCOURSE_HPP_ */
