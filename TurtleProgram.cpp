//	File Name: TurtleProgram.cpp
//	Programmer: Tabitha Roemish
//	File contains: TurtleProgram class definitions

#include "TurtleProgram.h"
#include <iostream>

using namespace std;

ostream& operator<< (ostream& out, const TurtleProgram& turtle)
{
	for (int i = 0; i < turtle.getLength(); i++)
	{
		out << turtle.getIndex(i);
		out << " ";
	}
	return out;
}

TurtleProgram::TurtleProgram(string direction, string angleOrLength)
{
	turtleArray = new string[2];
	turtleArray[0] = direction;
	turtleArray[1] = angleOrLength;
	length = CELL; // beginning length of array - commands come in pairs (CELL = 2)
}

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
