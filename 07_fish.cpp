/*
Lesson 7:Stacks and Queues

fish


100%

*/

#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::stack;
using std::cout;
using std::endl;



int solution(vector<int> &A, vector<int> &B)
{
	//100%
	stack <int> UpStream;
	stack <int> DownStream;;
	auto iter2 = B.begin();
	for (auto iter1 = A.begin(); iter1 != A.end(); iter1++, iter2++)
	{
		if (*iter2 == 0) //*iter2 Upstream
		{

			while (!DownStream.empty() && *iter1 > DownStream.top())
			{

				DownStream.pop();

			}
			if (DownStream.empty())
			{
				UpStream.push(*iter1);
			}


		}
		else //*iter2 Downstream
		{

			DownStream.push(*iter1);

		}

	}


	return DownStream.size() + UpStream.size();

}

/*
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <climits>
#include <list>
#include <numeric>

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
using std::copy;
using std::accumulate;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int> &A, vector<int> &B )
{
//75%
int sum;
auto iter = A.begin();
auto iter2 = B.begin();
auto nextiter = iter + 1;
auto nextiter2 = iter2 + 1;
bool finish = true;
do
{


while(iter < A.end()-1)
{
finish = true;
if (((*iter) > (*nextiter)) && ((*iter2) > (*nextiter2)))
{
A.erase(nextiter);
B.erase(nextiter2);
finish = false;
break;

}
else if (((*iter) < (*nextiter)) && ((*iter2) > (*nextiter2)))
{
A.erase(iter);
B.erase(iter2);
finish = false;
break;
}
iter++;
iter2++;
nextiter++;
nextiter2++;
}
iter = A.begin();
iter2 = B.begin();
nextiter = iter + 1;
nextiter2 = iter2 + 1;

sum = accumulate(B.begin(), B.end(), 0);


} while ((sum != 0) && (sum != B.size()) && finish == false);

cout << "sum="<<sum<<endl;

return	A.size();


}

*/

/*
int solution(vector<int> &A, vector<int> &B)
{
//75%
list <int> C(A.begin(), A.end());
list <int> D(B.begin(),B.end());



int sum;
auto iter = C.begin();
auto iter2 = D.begin();
int	CpreviousValue = *iter;
int	DpreviousValue = *iter2;
iter++;
iter2++;


bool finish = true;

do
{


while ( iter!= C.end())
{
finish = true;


if (((CpreviousValue) >(*iter)) && ((DpreviousValue) > (*iter2)))
{
C.erase(iter);
D.erase(iter2);
finish = false;
break;


}
else if (((CpreviousValue) < (*iter)) && ((DpreviousValue) > (*iter2)))
{
iter--;
iter2--;
C.erase(iter);
D.erase(iter2);
finish = false;

break;

}

CpreviousValue = *iter;
DpreviousValue = *iter2;
iter++;
iter2++;




}

iter = C.begin();
iter2 = D.begin();
CpreviousValue = *iter;
DpreviousValue = *iter2;
iter++;
iter2++;

sum = accumulate(D.begin(), D.end(), 0);


} while ((sum != 0) && (sum != D.size()) && finish == false);

cout << "sum=" << sum << endl;

return	C.size();


}

*/

int main(void)
{

	vector <int> A = { 4, 3, 2,1,5 };
	vector <int> B = { 0,1,0,0,0 };
	//	vector <int> A = { 4,  5 };
	//	vector <int> B = { 0,  1 };



	cout << solution(A, B) << endl;


	return 0;
}

