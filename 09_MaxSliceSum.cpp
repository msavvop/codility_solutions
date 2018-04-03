/*
Lesson 9: Maximum Slice Problem

MaxSliceSum




100%

*/
#include <vector>
#include <iostream>
#include <algorithm>
#include<numeric>

using std::cout;
using std::endl;
using std::vector;
using std::accumulate;
using std::max;

int solution(vector<int> &A) {
	int MaxSliceSum = A[0];
	for (size_t i = 1; i<A.size(); i++)
	{
		A[i] = max(A[i], A[i] + A[i - 1]);
		MaxSliceSum = max(A[i], MaxSliceSum);
	}
	return MaxSliceSum;
}

/*
int solution(vector<int> &A)
{
//84%
int MaxSliceSum=INT_MIN;
int sum = 0;

if (A.size() == 1)
{
return A[0];
}
for (int i = 0; i<A.size(); i++)
{

for (int j = A.size()-1;j>=i; j--)
{
auto iter1 = A.begin() + i;
auto iter2 = A.begin() + j+1;
sum = accumulate(iter1, iter2, 0);
MaxSliceSum = max(MaxSliceSum, sum);


//	for (int k = i, sum = 0; k <=j; k++)
//	{
//		sum += A[k];
//	    MaxSliceSum = max(MaxSliceSum, sum);
//	}

}


}




return MaxSliceSum;
}
*/

int main(void)
{
	vector <int> A = { 3, 2, -6, 4, 0 };
	//	vector <int> A{ -10,-20,-30 };
	cout << solution(A) << endl;

	return 0;
}