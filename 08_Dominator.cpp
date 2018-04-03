/*
Lesson 8: Leader

Dominator





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
			return find(A.begin(), A.end(), number1) - A.begin();
		}

	}

	return -1;

}

int main(void)
{
	vector <int>A = { 3, 4, 3, 2, 3, -1, 3, 3 };
	cout << solution(A) << endl;
	return 0;
}