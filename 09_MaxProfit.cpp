/*
Lesson 9:Max Slice Problem

MaxProfit




100%

*/

#include <iostream>
#include<algorithm>
#include <numeric>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

int solution(vector<int> &A)
{
	//100%
	vector <int> B(A.size());
	vector <int> C(A.size());
	int MaxProfit = 0;

	for (size_t i = 1; i<A.size(); i++)
	{
		B[i] = A[i] - A[i - 1];
		C[i] = max(B[i], B[i] + C[i - 1]);
		MaxProfit = max(C[i], MaxProfit);
	}


	return MaxProfit;

}


int main(void)
{
	vector <int> A = { 23171, 21011, 21123, 21366, 21013, 21367 };

	cout << solution(A) << endl;


	return 0;

}