/*
Lesson 6:Sorting
Distinct




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

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
	list<int> B(A.begin(), A.end());

	B.sort();

	B.unique();

	return	B.size();


}



int main(void)
{

	vector <int> A = { 2, 1, 1, 2, 3, 1 };






	cout << solution(A) << endl;


	return 0;
}
