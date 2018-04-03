/*

LESSON 3:Time Complexity
PermMissingElement


SCORE 100%
*/

// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using std::vector;
using std::cout;
using std::endl;
using std::function;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	if (A.size() == 0) return 1;
	if (A.size() == 1)
	{
		if (A[0] == 1)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}

	sort(A.begin(), A.end());
	auto iter = A.begin();

	function<int()> MissingTerm = [&]()->int
	{
		if ((*iter) != 1) return 0;
		for (; iter < A.end() - 1; iter++)
		{
			if ((*(iter + 1)) - (*iter) > 1) return *iter;
		}
		return *iter;
	};



	return MissingTerm() + 1;
}



int main(void)
{
	vector<int> A = { 3, 2 };
	cout << solution(A) << endl;

	return 0;
}