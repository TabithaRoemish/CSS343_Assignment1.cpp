//	File Name: TurtleProgram.h
//	Programmer: Tabitha Roemish
//	File Contains: Class declaration for TurtleProgram

#ifndef TURTLE_H
#define TURTLE_H
# define CELL 2 //each command is binary
				// I will use this to increment size of array 
				//since I'm not sure if sizeOf is allowed

#include<string>
#include <iostream>

using namespace std;

class TurtleProgram
{
	public:
		TurtleProgram(string direction = "", string angleOrLength = "");
		~TurtleProgram() { delete turtleArray; };

		string getIndex(int index) const { return turtleArray[index]; };
		int getLength() const { return length; };
		void setIndex(int index);

		bool operator==(TurtleProgram& turtle);
		bool operator!=(TurtleProgram& turtle);
		TurtleProgram operator=(TurtleProgram& turtle);
		TurtleProgram operator+(TurtleProgram& turtle);
		TurtleProgram operator+=(TurtleProgram& turtle);
		TurtleProgram operator*(int multiplier);
		TurtleProgram operator*=(int multiplier);
	private:
		string* turtleArray;
		int length;
};

ostream& operator<< (ostream& out, const TurtleProgram& turtle);

　
#endif
