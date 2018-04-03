/*
LESSON 5:Prefix sums

minAvgTwoSlice


60 out of 100 points
*/


#include <algorithm>
#include <vector>
#include <iostream>

#include <cfloat>
#include <numeric>


using std::vector;
using std::cout;
using std::endl;
using std::accumulate;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
	//60%
	double minAverage = DBL_MAX;
	double Average = DBL_MAX;


	int Answer = A.size();


	if (A.size() == 1)
	{
		Answer = 0;
		return Answer;
	}


	for (size_t P = 0; P < A.size(); P++)
	{

		for (size_t Q = P + 1; Q < A.size(); Q++)
		{
			Average = (accumulate(A.begin() + P, A.begin() + Q + 1, 0.0)) / (Q - P + 1);

			if (minAverage > Average)
			{
				minAverage = Average;

				Answer = P;

			}
			else if (minAverage == Average)
			{
				if (P<Answer)  Answer = P;
			}

		}

	}


	return Answer;
}



/*
int solution(vector<int> &A)
{
//60%
double minAverage = DBL_MAX;
double Average = DBL_MAX;

double sum;
//	int count;
int Answer = A.size();


if (A.size() == 1)
{
Answer = 0;
return Answer;
}


for (size_t P = 0; P < A.size(); P++)
{

for (size_t Q = P + 1; Q < A.size(); Q++)
{
sum = 0;
//			count = 0;
for (size_t j = P; j <=Q; j++)
{
sum += A[j];
//				count++;


}

Average = sum / (Q - P + 1);
//			cout << P << "\t" << Q << endl;
//			cout << "sum=" << sum << endl;;
//			cout << "count=" << count << endl;
//			cout << Average << endl;

if (minAverage > Average)
{

minAverage = Average;

Answer = P;
//				cout << "Answer="<<Answer<<endl;

}
else if (minAverage == Average)
{
if (P<Answer)  Answer=P;
}
}

}





return Answer;
}

*/

int main(void)
{

	//	vector <int> A = {10000,-10000 };
	vector <int> A = { 4, 2, 2, 5, 1, 5, 8 };





	cout << solution(A) << endl;


	return 0;
}
