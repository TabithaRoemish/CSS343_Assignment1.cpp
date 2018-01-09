//	File Name: TurtleProgram.cpp
//	Programmer: Tabitha Roemish
//	File contains: TurtleProgram class definitions

#include "TurtleProgram.h"
#include <iostream>

using namespace std;


//constructor
TurtleProgram::TurtleProgram(string direction, string angleOrLength)
{
	turtleArray = new string[CELL];
	turtleArray[0] = direction;
	turtleArray[1] = angleOrLength;
	length = CELL; // beginning length of array - commands come in pairs (CELL = 2)
}

//copy constructor
TurtleProgram::TurtleProgram(TurtleProgram& turtle)
{
	if (turtle != *this)
	{
		length = turtle.length;
		turtleArray = new string[length];
		for (int i = 0; i < length; i++)
			turtleArray[i] = turtle.turtleArray[i];
	}
}

//ostream overload (not a friend, defined out of class)
ostream& operator<< (ostream& out, const TurtleProgram& turtle)
{
	for (int i = 0; i < turtle.getLength(); i++)
	{
		out << turtle.getIndex(i);
		out << " ";
	}
	return out;
}

//boolean comparisons
bool TurtleProgram::operator==(TurtleProgram& turtle)
{
	string baseTurtle = "";
	string compareTurtle = "";

	for (int i = 0; i < turtle.getLength(); i++)
		baseTurtle += turtle.turtleArray[i];
	for (int l = 0; l < this->getLength(); l++)
		compareTurtle += this->turtleArray[l];

	return (baseTurtle == compareTurtle);
}

bool TurtleProgram::operator!=(TurtleProgram& turtle)
{
	bool answer = false;
	if (turtle == *this)
		answer = true;
	return answer;
}

//assignment operator
TurtleProgram TurtleProgram::operator=(TurtleProgram& turtle)
{
	if (turtle == *this)
		return *this;
	else
	{
		length = turtle.length;
		delete[] turtleArray;
		turtleArray = new string[length];
		for (int i = 0; i < length; i++)
			turtleArray[i] = turtle.turtleArray[i];
	}
	return *this;
}

//arithmetic overloads
