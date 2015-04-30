/*
 * Course.hpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef COURSE_HPP_
#define COURSE_HPP_
#include <unordered_map>
#include <iostream>

using namespace std;

class Course
{

public:
	void printCourse() const;
	Course(string name);


private:
	string name;


};




#endif /* COURSE_HPP_ */
