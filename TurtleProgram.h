//	File Name: TurtleProgram.h
//	Programmer: Tabitha Roemish
//	File Contains: Class declaration for TurtleProgram

#ifndef TURTLE_H
#define TURTLE_H


#include<string>
#include <iostream>

using namespace std;

class TurtleProgram
{
	public:
		TurtleProgram() { length = 0; turtleArray = NULL;};
		TurtleProgram(string direction, string angleOrLength);
		TurtleProgram(const TurtleProgram& turtle);
		~TurtleProgram() { delete[] turtleArray;};

		//no checks have been added for out of bounds index reference
		//use in main requires in bounds index references and proper string input
		string getIndex(int index) const { return turtleArray[index]; };
		int getLength() const { return length; };
		void setIndex(int index, string action) { turtleArray[index] = action; };
		void setLength(int lng) { length = lng; };

		bool operator==(const TurtleProgram& turtle) const;
		bool operator!=(const TurtleProgram& turtle) const;

		TurtleProgram& operator=(const TurtleProgram& turtle);

		const TurtleProgram operator+(const TurtleProgram& turtle) const;
		TurtleProgram& operator+=(const TurtleProgram& turtle);
		const TurtleProgram operator*(int multiplier) const;
		TurtleProgram& operator*=(int multiplier);

		
	private:
		string* turtleArray;
		int length;
};

ostream& operator<< (ostream& out, const TurtleProgram& turtle);

#endif
