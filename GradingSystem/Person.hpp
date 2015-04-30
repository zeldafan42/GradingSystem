/*
 * Person.hpp
 *
 *  Created on: 24.04.2015
 *      Author: Christoph Majcen
 *      		Arthur Bouz
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>

using namespace std;

class Person
{
public:
	Person(const string &name);
	virtual void printPerson() const = 0;
	virtual ~Person();

protected:
	string name;
};

#endif /* PERSON_HPP_ */
