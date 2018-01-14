//	File Name: TurtleProgram.cpp
//	Programmer: Tabitha Roemish
//	File contains: Main

#include "TurtleProgram.h"
#include <iostream>

using namespace std;

int main()
{
	TurtleProgram tp1;
	cout << "tp1: " << tp1 << endl;
	TurtleProgram tp2("F", "10");
	cout << "tp2: " << tp2 << endl;
	TurtleProgram tp3("R", "90");
	cout << "tp3: " << tp3 << endl;
	TurtleProgram tp4("F", "10");
	cout << "tp4: " << tp4 << endl;
	TurtleProgram tp5(tp2); 
	cout << "tp5 is a copy of tp2: " << tp5 << endl;
	
	//comparison operators
	cout << endl;
	cout << boolalpha;
	cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	cout << "tp2 and tp4 are == to each other: " << (tp2 == tp4) << endl;
	cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	cout << "tp2 and tp4 are != to each other: " << (tp2 != tp4) << endl;

	//set index
	cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	tp2.setIndex(0, "R");
	tp2.setIndex(1, "90");
	cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	
	//additional tests for += *=*
	tp1 = tp2 + tp3;
	cout << "tp1 now as tp2+tp3: " << tp1 << endl;
	tp4 += tp3;
	cout << "tp4 += tp3: " << tp4 << endl;
	tp1 = tp2 * 3;
	cout << "tp1 now as tp2 * 3: " << tp1 << endl;
	tp3 *= 4;
	cout << "tp3 *= 4: " << tp3 << endl;
	
	cin.get();

	cout << "Done." << endl;
	return 0;
}
