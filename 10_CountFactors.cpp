/*
Lesson 10: Prime and Composite Numbers
CountFactors

100%






*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <cmath>
using std::cout;
using std::endl;
using std::unordered_set;

int solution(int N)
{
	//100%
	int CountFactors=0;
	int i = 1;
	double SqrtN = sqrt(N);
	for (; i < SqrtN; ++i)
		if (N % i == 0)
		{
			CountFactors += 2;
			
		}
	if (i == SqrtN)	CountFactors++;

	return CountFactors;
}
/*
int solution(int N)
{
	//92%
	int i = 1;
	int CountFactors = 0;
	

	while(i * i < N)
	{
		if ((N % i) == 0) CountFactors += 2;
		i++;
	}

	if (i * i == N) CountFactors++;
	

	


	return CountFactors;
}
*/

/*
int solution(int N)
{
	int CountFactors=0;
	//78

	for (int i = 1; i <= N/2; i++)
	{
		if ((N%i) == 0) CountFactors++;
	}

	CountFactors++;
	

	return CountFactors;
}
*/
/*

int solution(int N)
{
//71%
	int CountFactors;
	unordered_set <int> set1;

	for (int i = 1; i <= N; i++)
	{
		if ((N%i) == 0) set1.insert(i);
	}

	CountFactors = set1.size();

	return CountFactors;
}
*/
int main(void)
{
//	int N = 24;

	int N = 1;

	cout << solution(N) << endl;

	return 0;

}