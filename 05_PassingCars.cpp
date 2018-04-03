/*
LESSON 5:Prefix sums
05_PassingCars.cpp





SCORE 100%

*/


#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>

using std::cout;
using std::endl;
using std::vector;
using std::function;

int solution(vector<int> &A)
{


	function <int()> PassingCars = [&]()->int
	{
		int count = 0;
		int count0 = 0;


		/*		for (size_t i = 0; i < A.size(); i++)
		{
		for (size_t j = i; j < A.size(); j++)
		{
		if ((A[i] == 0) && (A[j] == 1)) count++;
		}
		}

		*/

		for (size_t i = 0; i < A.size(); i++)
		{

			if (A[i] == 0) count0++;
			//όσα 0 εχεις τόσα ζευγάρια κάνεις με ένα 1. Τα 0 του count0 είναι αυτά μέχρι το i.

			if (A[i] == 1)
			{

				//όσα 1 έχεις μετράς count0 ζευγάρια για το κάθε 1. Το count0 αυξάνεται προς το τέλος του διαστήματος καθώς μετράει περισσότερα 0, δηλαδή το κάθε 1 κάνει περισσότερα ζευγάρια.
				count = count + count0;

			}
			if (count>1000000000) return -1;


		}



		return count;


	};


	return PassingCars();
}

int main(void)
{

	vector <int> A = { 0,1,0,1,1 };
	int B = solution(A);

	cout << B << "\t";


	cout << endl;
}