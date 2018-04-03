/*
LESSON 4:Counting Elements
PermCheck

SCORE 100%
*/
#include <iostream>
#include<algorithm>
#include<functional>
#include <vector>
#include <numeric>


using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::function;


int solution(vector<int> &A)
{

	if (A.size() == 0) return 0;


	sort(A.begin(), A.end());





	function<int()> PermVector = [&]()->int
	{
		size_t i;

		if (A[0] != 1) return 0;

		for (i = 0; i < (A.size() - 1); i++)
		{
			if ((A[i + 1] - A[i]) != 1) return 0;
		}

		if (A[i] != static_cast<int>(A.size()))	return 0;

		return 1;

	};
	return PermVector();

}

int main(void)
{
	vector <int> A = { 2,1,4,5,3 };

	cout << solution(A) << endl;

	return 0;

}