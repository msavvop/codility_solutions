/*
LESSON 4:Counting Elements
FrogRiverOne




SCORE 100%
*/

# include <iostream>
# include <vector>
# include <algorithm>
# include <functional>
# include <utility>
# include <map>
# include <iterator>
using namespace std;
using namespace std::placeholders;



int solution(int X, vector<int> &A)
{
	//    100%
	if (A.size() == 0)
		return 0;
	else if (A.size() == 1)
	{
		if (A[0] == 1)
			return 0;
		else
			return -1;
	}
	else
	{
		//    Δημιουργούμε ένα χάρτη στον οποίο τοποθετούνται οι τιμές (Α[i],i). Ο χάρτης αποτελείται από ζεύγη (θέση, χρόνος).
		//    Με τον τρόπο αυτό, για κάθε θέση A[i] κρατάμε μόνο τον μικρότερο χρόνο i που χρειάστηκε ο βάτραχος για να φτάσει σε αυτή.
		//    Αν κάποια θέση δεν έχει συμπληρωθεί, το μέγεθος του χάρτη θα είναι μικρότερο του X, και επιστρέφουμε την τιμή -1.
		//    Διαφορετικά, ο βάτραχος μπορεί να περάσει απέναντι και πρέπει να βρούμε το χρόνο που χρειάζεται εντοπίζοντας τη μέγιστη τιμη χρόνου i που περιέχεται στα στοιχεία του
		//     Αυτό επιτυγχάνεται με την max_element. Για τη σύγκριση των στοιχείων χρησιμοποιούμε μια συνάρτηση lambda που συγκρίνει τους χρόνους των ζευγών (second)
		//    Η συνάρτηση επιστρέφει ένα επαναλήπτη που δείχνει στο μέγιστο στοιχείο. Για να πάρουμε την τιμή του αντίστοιχου χρόνου, αρκεί η έκφραση mx->second
		map<int, int> B;
		for (int i = 0; i<A.size(); i++)
			B.insert(pair<const int, int>(A[i], i));

		if (B.size() != X)
			return -1;
		else
			return max_element(B.begin(), B.end(), [](pair<const int, int> p1, pair<const int, int> p2) {return p1.second<p2.second; })->second;
	}
}

/*
int solution(int X, vector<int> &A)
{
//81%

if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return -1;
}
else
{
return 0;
}

}



int i;

int maximum = 0;


auto iter = A.begin();

for (i = 1; i <= X; i++)

{
iter = max(iter,find(A.begin(), A.end(), i));
if ((iter) == A.end()) return -1;


}

maximum = iter - A.begin();




return maximum;





}

*/

/*
int solution(int X, vector<int> &A)
{
if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return -1;
}
else
{
return 0;
}

}



int i;

int max = 0;


auto iter = A.begin();
auto maxiter = A.begin();
for (i = 1; i <= X; i++)

{
iter = find(A.begin(), A.end(), i);
if ((iter) == A.end()) return -1;
if (maxiter < iter ) maxiter = iter ;

}

max = maxiter - A.begin();




return max;





}
*/

/*
int solution(int X, vector<int> &A)
{
if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return -1;
}
else
{
return 0;
}

}


function <int()> FrogRiver = [&]()->int
{
int i;

int max = 0;


auto iter = find(A.begin(), A.end(), 1);
if ((iter)==A.end()) return -1;
if (max < (iter - A.begin())) max = (iter - A.begin());
for (  i= 2; i <=X; i++)

{
iter = find(A.begin(), A.end(), i);
if ((iter)==A.end()) return -1;
if (max < (iter-A.begin())) max = (iter-A.begin());

}






return max;




};


return FrogRiver();
}
*/

/*

int solution(int X, vector<int> &A)
{
int i;
size_t j;
if (A.size() == 0) return -1;
if (A.size() == 1)
{
if (A[0] != 1)
{
return -1;
}
else
{
return 0;
}

}

bool found = false;
int max = 0;
for (i = 1; i <= X; i++)
{
for (j = 0; j < A.size(); j++)
{

if (A[j] == i)
{

if (max < j) max = j;
found = true;

break;
}
else
{
found = false;
}
}
if (found == false) return -1;


}




if (max == 0) max= -1;

return max;
}
*/


int main(void)
{
	/*	int X = 5;
	vector <int> A = { 1, 2, 3, 5, 3,4, 1 };
	*/
	int X = 5;
	vector <int> A = { 1, 3,1, 4,2,3,5,4 };



	cout << solution(X, A) << endl;
}

