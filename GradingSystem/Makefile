
CC=g++
CFLAGS=-std=c++11 -Wall -O

all: GradingSystem
	./GradingSystem

GradingSystem: GradingSystem.o Course.o GradedCourse.o Person.o Student.o Teacher.o
	${CC} ${CFLAGS} -o GradingSystem GradingSystem.o Course.o GradedCourse.o Person.o Student.o Teacher.o

GradingSystem.o: GradingSystem.cpp Course.hpp GradedCourse.hpp Person.hpp Student.hpp Teacher.hpp
	${CC} ${CFLAGS} -c -o GradingSystem.o GradingSystem.cpp

Course.o: Course.cpp Course.hpp
	${CC} ${CFLAGS} -c -o Course.o Course.cpp

GradedCourse.o: GradedCourse.cpp GradedCourse.hpp Course.hpp
	${CC} ${CFLAGS} -c -o GradedCourse.o GradedCourse.cpp

Person.o: Person.cpp Person.hpp
	${CC} ${CFLAGS} -c -o Person.o Person.cpp

Student.o: Student.cpp Student.hpp Person.hpp
	${CC} ${CFLAGS} -c -o Student.o Student.cpp

Teacher.o: Teacher.cpp Teacher.hpp Person.hpp
	${CC} ${CFLAGS} -c -o Teacher.o Teacher.cpp

clean:
	rm -f GradingSystem.o Course.o GradedCourse.o Person.o Student.o Teacher.o GradingSystem