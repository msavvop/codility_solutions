/*
LESSON 2 :Arrays
CyclicRotation






SCORE 100%
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <deque>
using std::cout;
using std::vector;
using std::deque;
using std::iterator;
using std::endl;

vector<int> solution(vector<int> &A, int K) {
	int temp = 0;
	if (A.empty()) return A;

	deque<int> B(A.size());

	copy(A.begin(), A.end(), B.begin());


	for (int i = 0; i < K; i++)
	{
		//		temp = (*(B.end() - 1));
		temp = B.back();
		B.pop_back();
		B.push_front(temp);




	}
	copy(B.begin(), B.end(), A.begin());

	return A;
}


int main(void)
{

	vector<int> A = { 3, 8, 9, 7, 6 };
	int K = 3;
	solution(A, K);
	auto iter1 = A.begin();
	for (; iter1 < A.end();)
	{
		cout << *iter1++;

	}

	cout << endl;
	return 0;


}