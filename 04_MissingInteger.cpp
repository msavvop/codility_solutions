/*
LESSON 4:Counting Elements




SCORE 100%
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <numeric>
# include <set>
# include <unordered_set>

using std::vector;
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::any_of;
using std::set;
using std::unordered_set;



int solution(vector<int> &A)
{
	unordered_set<int> C;
	C.reserve(A.size());
	sort(A.begin(), A.end());
	C.insert(A.begin(), A.end());

	//100%
	if (A.size() == 0) return -1;
	if (A.size() == 1)
	{
		if (A[0] != 1)
		{
			return 1;
		}
		else
		{
			return 2;
		}

	}



	for (int p = 1; p <= A.size(); p++)
	{

		if (C.count(p) == 0)
		{
			return p;
		}

	}


}


/*
int solution(vector<int> &A)
{
//66%
if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return 1;
}
else
{
return 2;
}

}



for (int p = 1;p<=A.size(); p++)
{

//			cout << "p=" << p<<endl;
if (!any_of(A.begin(), A.end(), [p](int a){return (a==p); }))
{
return p;
}

}


}
*/

/*
int solution(vector<int> &A)
{

//66%
if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return 1;
}
else
{
return 2;
}

}


function <int()> MissingNum = [&]()->int
{
size_t i;



sort(A.begin(), A.end());
auto iter = find(A.begin(), A.end(), 1);

if ((iter) == A.end()) return 1;

for (i = 2; i < A.size(); i++)

{
iter = find(A.begin(), A.end(), i);
if ((iter) == A.end()) return i;


}






return i;
};





return MissingNum();
}
*/
int main(void)
{

	vector <int> A = { 1, 3, 6,4,1 ,2 };

	//	vector <int> A = { 1, 11, 2, 5, 3, 7, 8, 10 };
	cout << solution(A) << endl;
	return 0;
}