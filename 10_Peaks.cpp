/*
Lesson 10: Prime and Composite Numbers

Peaks


100%

*/
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::set;







int solution(vector<int> &A)
{
	//100%
	int Blocks = 0;
	set <size_t> peaks;



	for (size_t i = 1; i < A.size() - 1; i++)
	{
		if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
			peaks.insert(i);
		}
	}


	for (size_t sections = 1; sections < A.size(); sections++)
	{
		if (((A.size()) % sections) == 0)
		{
			size_t blockNumber = 0;
			size_t block = (A.size()) / sections;
			for (size_t p : peaks)
			{
				if (blockNumber * block <= p && p < (blockNumber + 1) * block)
				{
					blockNumber++;
				}
			}
			if (blockNumber >= sections)
			{
				Blocks = sections;
			}
		}
	}

	return Blocks;






}

/*
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;






int solution(vector<int> &A)
{
	int Blocks = 0;
	unordered_set <size_t> peaks;
	

	
	for (size_t i = 1; i < A.size() - 1; i++) 
	{
		if (A[i] > A[i-1] && A[i] > A[i + 1]) {
			peaks.insert(i);
		}
	}

	
	for (size_t sections = 1; sections < A.size(); sections++) 
	{
		if (((A.size()) % sections) == 0) 
		{
			size_t blockNumber = 0;
			size_t block = (A.size()) / sections;
			for (size_t p : peaks) 
			{
				if (blockNumber * block <= p && p < (blockNumber + 1) * block) 
				{
					blockNumber++;
				}
			}
			if (blockNumber >= sections) 
			{
				Blocks= sections;
			}
		}
	}

	return Blocks;




	

}
*/

int main(void)
{
//	vector <int> A = { 1,2,3,4,3,4,1,2,3,4,6,2 };
	vector <int> A = { 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };
	void * pointer1;
	cout << sizeof(pointer1) << endl;
	cout << solution(A) << endl;

	return 0;
}

