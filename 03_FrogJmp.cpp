// FrogJmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*

LESSON 3: Time Complexity
Frogjmp





SCORE 100%

*/
// you can use includes, for example:
// #include <algorithm>
#include <iostream>


using std::cout;
using std::endl;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
	// write your code in C++11 (g++ 4.8.2)
	double r;
	r = (Y - X) / D;
	int i = static_cast<int>(r);

	if ((i*D) >= (Y - X))
	{
		return i;
	}
	else
	{
		return ++i;
	}


}

int main(void)
{
	int X = 1;
	int Y = 5;
	int D = 2;

	cout << "number of steps is  \t" << solution(10, 85, 30) << endl;;

	return 0;

}
