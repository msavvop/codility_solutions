/*

LESSON 3:Time Complexity
TapeEquilibrium

SCORE 100%
*/

// you can use includes, for example:
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using std::vector;
using std::cout;
using std::iterator;
using std::endl;



// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	//100%
	vector<float> B(A.size());


	if (A.empty()) return 0;

	if (A.size() == 1) return A[0];

	copy(A.begin(), A.end(), B.begin());

	auto iter = B.begin();



	double first_part = *(B.begin());
	double last_part = accumulate(B.begin() + 1, B.end(), 0.0f);
	double minimum = fabs(first_part - last_part);
	double difference = minimum;
	//	 cout << "difference=" << difference << "\t";
	for (iter = B.begin() + 1; iter < B.end() - 1; iter++)
	{

		first_part = first_part + *iter;
		last_part = last_part - *iter;
		difference = fabs(first_part - last_part);
		//		cout << "difference="<<difference<<"\t";
		if (difference <minimum) minimum = difference;





	}
	//	cout << endl;
	return static_cast<int>(minimum);

}


/*

//50%
int solution(vector<int> &A) {
vector<float> B(A.size());


if (A.empty()) return 0;

if (A.size() == 1) return A[0];

copy(A.begin(), A.end(), B.begin());

auto iter = B.begin();




double minimum = fabs(*(B.begin())-accumulate(B.begin() + 1, B.end(), 0.0f));
double difference=minimum;
//	 cout << "difference=" << difference << "\t";
for (iter = B.begin()+1; iter < B.end()-1; iter++)
{


difference = fabs(accumulate(B.begin(), iter+1, 0.0f) - accumulate(iter + 1, B.end(), 0.0f));
//		cout << "difference="<<difference<<"\t";
if (difference <minimum) minimum=difference;





}
//	cout << endl;
return static_cast<int>(minimum);

}
*/
int main(void)
{
	//	vector<int> A = { 0, -147483648, -147483648 };
	vector<int> A = { 3, 1, 2, 4, 3 };
	cout << solution(A) << endl;

	return 0;
}
