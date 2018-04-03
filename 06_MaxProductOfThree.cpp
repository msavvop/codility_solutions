/*
Lesson 6:Sorting

MaxProductOfThree



100 out of 100 points

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

	sort(A.begin(), A.end(), greater<int>());
	int prod1, prod2;
	prod1 = A[0] * A[1] * A[2];
	prod2 = A[0] * A[A.size() - 2] * A[A.size() - 1];

	return	max(prod1, prod2);


}



int main(void)
{

	vector <int> A = { -5, 5, -5,  4 };






	cout << solution(A) << endl;


	return 0;
}
