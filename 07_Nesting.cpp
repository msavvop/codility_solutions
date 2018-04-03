/*
Lesson 7
Stacks and Queues

Nesting



100%

*/


#include <string>
#include <stack>
#include <iostream>

using std::stack;
using std::string;
using std::cout;
using std::endl;

int solution(string &S)
{
	//100%
	stack <char> A;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '(')
		{
			A.push(S[i]);
		}
		else if (S[i] == ')')
		{
			if (A.size() == 0)
			{
				return 0;
			}
			else
			{
				A.pop();
			}
		}
	}

	if (A.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

int main(void)
{
	//	string S = "(()(())())";
	string S = "())";

	cout << solution(S) << endl;

	return 0;
}