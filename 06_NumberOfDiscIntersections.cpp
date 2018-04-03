/*
Lesson 6:Sorting

NumberOfDiscIntersections



81 out of 100 points
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <climits>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::sort;
using std::unique;
using std::list;
using std::greater;
using std::max;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
	int i;

	int count = 0;

	/*	for (i = 0; i < static_cast <int>(A.size()); i++)
	{
	for (int j = i +A[i]+1; j < (static_cast <int>(A.size())); j++)
	{
	if (A[i] >= INT_MAX)
	{
	count++;
	continue;
	}
	if ((i+A[i])  >= (j - A[j]))	count++;
	if (count > 10000000) return -1;
	}

	}

	return	count;
	*/

	for (i = 0; i < static_cast <int>(A.size()); i++)
	{

		for (int j = i + 1; j < (static_cast <int>(A.size())); j++)
		{
			if (A[i] >= INT_MAX)
			{
				count++;
				continue;
			}
			if ((i + A[i]) >= (j - A[j]))	count++;
			if (count > 10000000) return -1;
		}

	}

	return	count;


}



int main(void)
{

	vector <int> A = { 1, 5,2,1, 4,0 };






	cout << solution(A) << endl;


	return 0;
}

