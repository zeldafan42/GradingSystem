/*
 * GradedCourse.hpp
 *
 *  Created on: 24.04.2015
 *      Author: Christine
 */

#ifndef GRADEDCOURSE_HPP_
#define GRADEDCOURSE_HPP_

#include "Course.hpp"

class GradedCourse
{
public:
	void printCourse() const;
	GradedCourse(int grade, Course * course);
	void gradeStudent(int grade);

private:
	int grade;
	Course * course;

};
#endif /* GRADEDCOURSE_HPP_ */
