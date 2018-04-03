/*
LESSON 1:Iterations




SCORE 100%
*/



#include <iostream>

using std::cout;
using std::endl;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int function1(int N)
{
	return N >> 1;
}
int solution(int N) {
	int maxint = 2147483647;
	if (N>maxint) return -1;
//	bool startcount = false;
	int maxcount = 0;
	int mask = 1;
	int count = 0;
	while (N>0)
	{

		if (N&mask)
		{
			count = 0;
//			startcount = true;
		}
		else
		{
//			if (startcount == true) count++;
			count++;
			if (maxcount<count) maxcount = count;
		}

		N = function1(N);

	}
	return maxcount;

}





int main(void)
{
	int N = 1041;
//	int N = 529;
	int answer;
	answer = solution(N);

	cout << answer << endl;

	return 0;
}