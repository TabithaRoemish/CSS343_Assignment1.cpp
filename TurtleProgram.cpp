//	File Name: TurtleProgram.cpp
//	Programmer: Tabitha Roemish
//	File contains: TurtleProgram class definitions

#include "TurtleProgram.h"
#include <iostream>

using namespace std;


//constructor
TurtleProgram::TurtleProgram(string direction, string angleOrLength)
{
	if(direction !=" " && angleOrLength != " ")
	{
	turtleArray = new string[2]; //beginning length of array - commands come in pairs
	turtleArray[0] = direction;
	turtleArray[1] = angleOrLength;
	length = 2; // beginning length of array - commands come in pairs 
	}
}

//copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram& turtle)
{
		length = turtle.length;
		turtleArray = new string[length];
		for (int i = 0; i < length; i++)
			turtleArray[i] = turtle.turtleArray[i];
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
bool TurtleProgram::operator==(const TurtleProgram& turtle) const
{
	string baseTurtle = "";
	string compareTurtle = "";

	for (int i = 0; i < turtle.getLength(); i++)
		baseTurtle += turtle.turtleArray[i];
	for (int l = 0; l < this->getLength(); l++)
		compareTurtle += this->turtleArray[l];

	return (baseTurtle == compareTurtle);
}

bool TurtleProgram::operator!=(const TurtleProgram& turtle) const
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

TurtleProgram TurtleProgram::operator+(TurtleProgram& turtle)
{
	TurtleProgram answer;
	int size = turtle.getLength() + this->getLength();
	answer.setLength(size);
	answer.turtleArray = new string[size];
	for (int i = 0; i < this->getLength(); i++)
		answer.turtleArray[i] = this->turtleArray[i];
	for (int m = 0; m < turtle.getLength(); m++)
		answer.turtleArray[m + this->getLength()] = turtle.turtleArray[m];
		
	return answer;

}

TurtleProgram TurtleProgram::operator+=(TurtleProgram& turtle)
{
	return *this = *this + turtle;
}

TurtleProgram TurtleProgram::operator*(int multiplier)
{
	TurtleProgram answer;
	int index = 0;
	answer.setLength(this->getLength() * multiplier);
	answer.turtleArray = new string[answer.getLength()];

	for (int x = 0; x < multiplier; x++)
	{
		answer += *this;
	}

	return answer;
}

TurtleProgram TurtleProgram::operator*=(int multiplier)
{
	return *this = *this * multiplier;
}

