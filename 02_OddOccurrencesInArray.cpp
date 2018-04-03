/* LESSON 2:Arrays


--------------------------------------------------------------------------------------------------------------------------------------
score: 100 of 100 με unordered_set ΚΑΙ unordered_multiset 
(βασικά "κόβει" χρόνο στο βρόγχο γιατί ελέγχει το πλήθος μια μόνο φορά για κάθε αριθμό)
score: 88 of 100 με unordered_multiset
score: 77 of 100 με multiset
score: 66 of 100 με find_if
*/
# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <set>
# include <unordered_set>
using namespace std;


int solution(vector<int> &A)
{
	//	100%
	// write your code in C++11 (g++ 4.8.2)

	unordered_multiset<int> B;
	B.reserve(A.size());

	unordered_set<int> C;
	C.reserve(A.size());

	sort(A.begin(), A.end());
	C.insert(A.begin(), A.end());
	B.insert(A.begin(), A.end());

		//	Βάζουμε τα στοιχεία του πίνακα σε δύο σετ.
	//	Το set C περιέχει τα στοιχεία από μια μόνο φορά, οπότε έχει λίγα στοιχεία.
	//	Το multiset D περιέχει τα στοιχεία πολλές φορές, οπότε έχει πολλά στοιχεία αλλά διατηρεί τις πολλαπλότητες
	//  Για να αυξήσουμε την απόδοση, κάνουμε βρόγχο στο C κοιτάζοντας την πολλαπλότητα του στοιχείου στο D...
	//	Με τον τρόπο αυτό ο έλεγχος περιττότητας γίνεται μόνο μια φορά για κάθε στοιχείο.
	for (const int & occurrences : C)
		if (B.count(occurrences) % 2 == 1)
			return occurrences;

	/*	for (auto iter = C.begin(); iter != C.end(); iter++)
	if (B.count(*iter) % 2 == 1)
	return *iter;
	*/
}
/*
int oddOccurrencesInArray(vector<int> &A)
{
//	100%
// write your code in C++11 (g++ 4.8.2)

unordered_multiset<int> B;
B.reserve(A.size());

unordered_set<int> C;
C.reserve(A.size());

sort(A.begin(), A.end());
C.insert(A.cbegin(), A.cend());
B.insert(A.cbegin(), A.cend());

//	Βάζουμε τα στοιχεία του πίνακα σε δύο σετ.
//	Το set C περιέχει τα στοιχεία από μια μόνο φορά, οπότε έχει λίγα στοιχεία.
//	Το multiset D περιέχει τα στοιχεία πολλές φορές, οπότε έχει πολλά στοιχεία αλλά διατηρεί τις πολλαπλότητες
//  Για να αυξήσουμε την απόδοση, κάνουμε βρόγχο στο C κοιτάζοντας την πολλαπλότητα του στοιχείου στο D...
//	Με τον τρόπο αυτό ο έλεγχος περιττότητας γίνεται μόνο μια φορά για κάθε στοιχείο.

for (const int & occurrences : C)
if (B.count(occurrences) % 2 == 1)
return occurrences;
}
*/
int main(void)
{
	int occurrences;
	vector<int> A{ 9, 3, 9, 3, 9, 7, 9 };

	occurrences = solution(A);
	cout << "Array: ";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
	cout << "\nOdd Occurrences In Array: " << occurrences << endl;

}
/*
int oddOccurrencesInArray1(vector<int> &A)
{
//	88%
// write your code in C++11 (g++ 4.8.2)

unordered_multiset<int> B;
B.reserve(A.size());
B.insert(A.cbegin(),A.cend());

for (const int & occurrences :B)
if (B.count(occurrences)%2==1)
return occurrences;
}

int oddOccurrencesInArray2(vector<int> &A)
{
//	77%
// write your code in C++11 (g++ 4.8.2)

multiset<int> B;
B.reserve(A.size());
B.insert(A.cbegin(),A.cend());

for (const int & occurrences :B)
if (B.count(occurrences)%2==1)
return occurrences;
}
int oddOccurrencesInArray3(vector<int> &A)
{
//	66%
// write your code in C++11 (g++ 4.8.2)

auto x=find_if(A.cbegin(),A.cend(),[&A](int a){return count (A.cbegin(),A.cend(),a)%2 == 1 ;});
return *x;
}
*/


/*




SCORE 66%


*/

/*
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>


using std::cout;
using std::endl;
using std::vector;
using std::count;



int solution(vector<int> &A) {
if (A.size() == 1) return (*A.begin());
if (A.empty()) return 0;

auto iter = find_if(A.begin(), A.end(),
[&A](int a)->bool {

return count(A.begin(), A.end(), a) % 2 != 0;
});

return *iter;
}


-----------------------------
vector<int>& resized(vector<int> &A)
{
auto iter = A.begin() + 1;
int temp;
for (; iter < A.end(); iter++)
{
temp = (*(A.begin()));

if ((*iter) == temp)
{
A.erase(iter);
A.erase(A.begin());
return A;
}

}
return A;

}

int solution(vector<int> &A) {
// write your code in C++11 (g++ 4.8.2)
if (A.size() == 1) return (*A.begin());
if (A.empty()) return 0;

while (A.size() != 1)
{
resized(A);

auto iter = A.begin();
for (; iter < A.end(); iter++)
{
cout << *iter << "\t";
}
cout << endl;

}

return (*A.begin());

}


int solution(vector<int> &A) {
if (A.size() == 1) return (*A.begin());
if (A.empty()) return 0;
int temp;

for (size_t i = 0; i < A.size(); i++)
{

temp = (A[i]);
if (temp == 0) continue;
if ((i == A.size() - 1) && temp != 0) return temp;




for (size_t j = i + 1; j < A.size(); j++)
{

//            if(A[j]==0) continue;
if ((A[j] == temp) && (A[j] != 0))
{

A[i] = 0;
A[j] = 0;


break;
}
else if (j == A.size() - 1) return temp;

}
}

return 0;
}





------------------------------

int main(void)
{
vector<int> A = { 9, 3, 9, 3, 9, 7, 9 };

int answer;
answer = solution(A);

cout << "answer="<<answer;

return 0;
}
*/