/*

LESSON 4:Counting Elements

MaxCounter




SCORE 100%
*/


#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include <numeric>
#include <cmath>
#include <map>
#include <utility>
#include <iterator>
#include <set>


# include <unordered_set> 

using std::cout;
using std::endl;
using std::vector;
using std::function;
using std::max;
using std::map;
using std::pair;
using namespace std::placeholders;
using std::unordered_set;
using std::unordered_multiset;



vector<int> solution(int N, vector<int> &A)
{
	//    100%
	vector<int> b(N, 0);
	int local{}, mx{};

	//    �� ����� ���� ��������� ����� ����������� max counter ������, ���������� �� ��� ��������� count �� ������ ��� ��������� ��� � �� ���� N+1.
	//    -    �� ��� ������� �����, ��������� �� for, ��������� ��� ������ b ��� ��� ������������.
	//    -    �� ���� �� ������� ����� max counter, ���� ������������ ������ ����� ��� �������� ������ �����������.
	//    -    �� �������� ������� ������� KAI ������� max counter, ��������� ��� ������ ������ ��� ������������

	int cnt = count(A.begin(), A.end(), N + 1);

	if (cnt == 0)
	{
		for (int i = 0; i < A.size(); i++)
			b[A[i] - 1]++;
		return b;
	}
	else if (cnt == A.size())
		return b;
	else
	{

		//    ��� ������ ���� ������� ��� �������� ��� ������� ������� ��� ������� max counter.
		//    ������, ��������� �� ��� ��������� find_if ��� ����� ���� ��� ������ ��� ������� ������ ����������, ��� ������� ����������� ����� (bg) ��� ������ (nd) ���� ���� ���.
		//    � ����� ����� ��� ������� max counter ���� ���� ��� ������ �������� ��� ������ ������.
		//
		//    ��� �������� �������� ��� ������ ���� ���������� nd. ���� ����� ����� ���� �� A.end() �������������� break ��� �� ������������ �� ������.
		//    �� ��� ��������� find_if ����������� ��� ����� ������ max counter ��� �������� [bg,A.end()] ��� ��� ���������� ��� nd.
		//    ������������ �� unordered_set/unordered_multiset s, s1, ������������ �� ���� ��� �� �������� ��� [bg,nd].
		//    ��, ��� ���������� ���, �� ������� ��� ��� �� �������� 3,4,4 ��� ���������� ���� �� ����� 6.
		//
		//    -    �� �� ��� ����� ����, ������ ���������� ������� max counter. ���� ��������� ���� ���� ��������� �� bg, nd, ����� ��� ������� ���� ����.
		//        �� � ��������� ���� ��� ������ ������ ����������� �� �������� ������, ����� � ��������� �� ��� find_if �� ������� �������� �� ����� �������� (bg).
		//        ��� ���������� �� �� ��� 3, 1, 6, 6, 1, 4, 4, �� ������ � ����� ��������� ��� 3,1, ��� ���� ������� �� bg �� ������ ���������� ��� ������� 6. � ��� find_if �� �������� ���� 
		//    �� ���� ��������.
		//    -    �� �� ��� ����� ��������, �� ��� range for ��� s ���������� ��� ������� ������������ ��� ��������� ��� s2 (local), ��� ����� ��� ����������� ��� mx.
		//
		//    ���� ������� ��������� ������� �� ������� �� �������� ��� ���������� ���� �� nd. ����, ������ �� ��������� ��� ���� ��� bg ��� �� ������� ��� ������� �������� ��� �� ������ nd.
		//    ���� �� ������������ �� ��� if ���� ���� ��� ������� ��� ������� �� �� ����� ��� nd, bg �����������. ���� ��������� ���� ���� ����� ��������� � ���� ����������� ��������� max counter.
		//    �� ���� ������� ��������� ����, ������� �� ������������������� �� ���� ���������.
		//
		//    ���� ���������� �� ��������� max counter, ������������ � �������, ��� ��������� ��� ������ ��� �������� b �� ��� ���� mx.
		//    �������������� ��� ���� ��� bg ��� ������� ��� ������� �������� ��� �, ��� �� ����������� ��� ������ ��� �� �������� ���� ����� �� ����� ��� �,
		//    �� ���� ��������� ��������� ��� ���������� ���� ��� b, ��� �� ������������ ���� �� ����� ��� ����������.
		//
		//     ��� ������ ����������, ������ �� nd, bg �������� ��� �������� �[0]=3
		//    ��� ����� ���� ��� �� ������ � ������� ������� �� ��������� �� �������� 3,4,4, �� ����� ���������� ���� �� 6.
		//    �� ������ ���� ��������� �� ������ �� ������� �� �������� 1,4,4 ��� ���������� ���� �� 6.
		//    � ����� ����� ��� ���� �

		auto bg = find_if(A.begin(), A.end(), [N](int a) {return a != N + 1; });
		auto nd = bg;

		while (nd != A.end())
		{
			if (nd != bg)
				bg = next(nd);
			nd = find_if(bg, A.end(), [N](int a) {return a == N + 1; });
			if (nd == A.end()) break;

			unordered_multiset<int> s(bg, nd);
			unordered_set<int> s2(bg, nd);
			local = 0;

			if (s2.empty())
			{
				bg++;
				nd = bg;
			}
			else
			{
				for (int a : s2)
					if (s.count(a) > local) local = s.count(a);
				mx += local;
			}
		}

		fill(b.begin(), b.end(), mx);
		for (auto i = distance(A.begin(), bg); i != A.size(); i++)
			b[A[i] - 1]++;

		return b;
	}
}
/*
vector<int> solution(int N, vector<int> &A)
{
//77%
vector<int> B(N,0) ;



if (A.size() == 1)
{
if (A[0] <= N)
{
B[(A[0]) - 1]++;
return B;
}
else
{
return B;
}

}



size_t i;

int maximum = 0;



for (i = 0; i < A.size(); i++)

{

if (A[i] < (N + 1))
{
maximum=max(maximum,++(B[(A[i]) - 1]));

}
else
{
for (int j = 0; j < N; j++)
{
B[j] = maximum;
}

}

}









return B;
}
*/
/*
vector<int> solution(int N, vector<int> &A)
{
//77%
vector<int> B(N);

for (int i = 0; i < N; i++)
{
B[i] = 0;
}

if (A.size() == 1)
{
if (A[0] <=N)
{
B[(A[0])-1]++;
return B;
}
else
{
return B;
}

}


function <vector<int>()> MaxCounter = [&]()->vector<int>
{
size_t i;

int max = 0;



for (i = 0; i < A.size(); i++)

{

if (A[i] < (N+1))
{
++(B[(A[i])-1]);
if (max < (B[(A[i])-1])) max = (B[A[i]-1]);
}
else
{
for (int j = 0; j < N; j++)
{
B[j] = max;
}

}

}






return B;


};


return MaxCounter();
}
*/

int main(void)
{
	int N = 5;
	vector <int> A = { 3, 4, 4, 6, 1 ,4, 4 };
	vector <int>B = solution(N, A);
	for (int i = 0; i < N; i++)
	{
		cout << B[i] << "\t";

	}
	cout << endl;
}