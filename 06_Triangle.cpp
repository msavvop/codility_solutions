/*
Lesson 6:Sorting

Triangle



100 out of 100 points

*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <climits>

using std::vector;
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::sort;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
	if (A.size() < 3) return 0;
	if (A.size() > 100000) return 0;


	sort(A.begin(), A.end());

	for (int i = 0; i < A.size() - 2; i++)
	{


		if (A[A.size() - 3] == INT_MAX) return 1;

		if (A[i]<INT_MAX / 2)
		{
			int sum = A[i] + A[i + 1];


			if (sum > A[i + 2])
			{


				return 1;
			}
		}
		else
		{
			double sum = static_cast<double>(A[i]) / 2. + static_cast<double>(A[i + 1]) / 2.;
			if (sum > static_cast<double>(A[i + 2]) / 2.)
			{


				return 1;
			}
		}

	}

	return 0;
}



int main(void)
{

	vector <int> A = { 10,2,5,1,8,20 };






	cout << solution(A) << endl;


	return 0;
}
