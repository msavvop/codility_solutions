/*
Lesson 8:Leader

EquiLeader




100%

*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iterator>
#include <algorithm>

using std::unordered_set;
using std::unordered_multiset;
using std::vector;
using std::cout;
using std::endl;

int solution(vector<int> &A)
{
	//100%
	unordered_set <int> set1;
	unordered_multiset <int> multiset1;

	int countall = 0;
	int counthalf1 = 0;

	int leader;
	int half = A.size() / 2;

	for (auto number : A)
	{
		set1.insert(number);
		multiset1.insert(number);
	}

	for (auto number1 : set1)
	{
		if (multiset1.count(number1) >half)
		{
			leader = number1;
			countall = multiset1.count(number1);

		}


	}
	//	cout << "leader=" << leader<<endl;


	if (countall == 0) return 0;

	int count = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] == leader) counthalf1++;
		if (((counthalf1 * 2) > i + 1) && (((countall - counthalf1) * 2)) > (A.size() - i - 1)) count++;

	}






	return count;


}

int main(void)
{
//		vector <int>A = { 4, 3, 4, 4, 4, 2 };
	vector <int>A = { 4, 4, 2, 5, 3, 4, 4, 4 };


	cout << solution(A) << endl;
	return 0;
}
