/*
LESSON 5:Prefix sums




100 out of 100 points
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::any_of;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{

	//    100%
	vector<int> ans, A, C, G, T;

		//    Βασικά, η ιδέα εδώ είναι να σαρώσουμε την συμβολοσειρά μόνο μια φορά, και να αποθηκεύσουμε τα αποτελέσματα της σάρωσης σε 4 νέα διανύσματα A, C, G, T.
	//    Τα διανύσματα αυτά θα περιέχουν τις θέσεις όλων των A/C/G/T που έχει η συμβολοσειρά.

	for (int i = 0; i<S.size(); i++)
	{
		if (S[i] == 'A')    A.push_back(i);
		if (S[i] == 'C')    C.push_back(i);
		if (S[i] == 'G')    G.push_back(i);
		if (S[i] == 'T')    T.push_back(i);
	}

	//    Αφού δημιουργήσουμε τα διανύσματα, ξεκινάμε τις αναζητήσεις.
	//    Για κάθε αναζήτηση αποθηκεύουμε τα όρια αναζήτησης P[i], Q[i] στις μεταβλητές p και q.
	//    Ακολούθως χρησιμοποιούμε τον αλγόριθμο any_of για να βρούμε αν κάποιο στοιχείο στο διάνυσμα Α έχει τιμή που πέφτει ανάμεσα στα όρια [p,q+1]
	//    Αν βρεθεί κάποιο στοιχείο, τοποθετούμε την τιμή 1 στο διάνυσμα επιστροφής, αλλιώς συνεχίζουμε την αναζήτηση στα επόμενα διανύσματα.

	for (int i = 0; i<P.size(); i++)
	{
		int p = P[i];
		int q = Q[i];
		if (any_of(A.begin(), A.end(), [p, q](int a) {return p <= a && a<q + 1; }))
			ans.push_back(1);
		else if (any_of(C.begin(), C.end(), [p, q](int a) {return p <= a && a<q + 1; }))
			ans.push_back(2);
		else if (any_of(G.begin(), G.end(), [p, q](int a) {return p <= a && a<q + 1; }))
			ans.push_back(3);
		else if (any_of(T.begin(), T.end(), [p, q](int a) {return p <= a && a<q + 1; }))
			ans.push_back(4);
	}
	return ans;
}

/*

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{

//62%


vector <int> Answer(P.size());

auto isA = [](int elem){

return elem == 'A'; };

auto isC = [](int elem){

return elem == 'C'; };

auto isG = [](int elem){

return elem == 'G'; };


if (S.length() == 1)
{

if (S[0] == 'A') Answer[0] = 1;
if (S[0] == 'C') Answer[0] = 2;
if (S[0] == 'G') Answer[0] = 3;
if (S[0] == 'T') Answer[0] = 4;


return Answer;
}

for (size_t j = 0; j < P.size(); j++)
{
auto iter1 = S.begin() + P[j];
auto iter2 = S.begin() + Q[j] + 1;


if (any_of(iter1, iter2, isA))
{
Answer[j] = 1;


}
else if (any_of(iter1, iter2, isC))
{
Answer[j] = 2;


}
else if (any_of(iter1, iter2, isG))
{
Answer[j] = 3;


}
else
{
Answer[j] = 4;
}

}







return Answer;
}
*/
/*
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{

//62%

vector <int> S1(S.length());
vector <int> Answer(P.size());
transform(S.begin(), S.end(), S1.begin(), [&S](char ch1)->int{
if (ch1 == 'A') return 1;
if (ch1 == 'C') return 2;
if (ch1 == 'G') return 3;
if (ch1 == 'T') return 4; }
);


if (S.length() == 1)
{
Answer[0] = S1[0];
return Answer;
}

for (int j = 0; j < P.size(); j++)
{
auto iter1 = S1.begin() + P[j];
auto iter2 = S1.begin() + Q[j]+1;

Answer[j] = *min_element(iter1,iter2);

}






return Answer;
}

*/

/*
vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{

//62%
vector <int> S1(S.length());
vector <int> Answer(P.size());

for (int i = 0; i < S.length(); i++)
{
if (S[i] == 'A') S1[i] = 1;
if (S[i] == 'C') S1[i] = 2;
if (S[i] == 'G') S1[i] = 3;
if (S[i] == 'T') S1[i] = 4;



}

if (S.length() == 1)
{
Answer[0] = S1[0];
return Answer;
}

for (int j = 0; j < P.size(); j++)
{
int min = 4;
for (int i = P[j]; i <= Q[j]; i++)
{
if (min>S1[i])  min = S1[i];
if (min == 1) break;




}
Answer[j] = min;

}





return Answer;
}

*/

int main(void)
{

	vector <int> P = { 2, 5, 0 };
	vector <int> Q = { 4, 5, 6 };
	string S = "CAGCCTA";


	/*
	vector <int> P = { 0,0,1 };
	vector <int> Q = { 0,1,1 };
	string S = "TC";
	*/
	vector<int> R;


	R = solution(S, P, Q);
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << endl;
	}

	return 0;
}