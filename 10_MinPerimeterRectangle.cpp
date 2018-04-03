/*
Lesson 10: Prime and Composite Numbers

MinPerimeterRectangle


100%



*/
#include <iostream>
#include <cmath>


using std::cout;
using std::endl; 

int solution(int N)
{
	int MinPerimeter;
	int SqrtN = sqrt(N);
	int i = 1;
	int side=1,OtherSide=1;
	for (; i <= SqrtN; i++)
	{
		
		if ((N%i) == 0) side = i;
	}
	OtherSide = N / side;

	MinPerimeter = 2 * (side + OtherSide);
	

	return MinPerimeter;
}

int main(void)
{
	int N = 30;

	cout << solution(N) << endl;

	return 0;
}

