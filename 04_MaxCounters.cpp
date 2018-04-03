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

	//    Σε πρώτη φάση βρίσκουμε πόσες διαδικασίες max counter έχουμε, βρίσκοντας με τον αλγόριθμο count το πλήθος των στοιχείων του Α με τιμή N+1.
	//    -    Αν δεν υπάρχει καμία, προχωράμε με for, γεμίζουμε τον πίνακα b και τον επιστρέφουμε.
	//    -    Αν όλες οι εντολές είναι max counter, τότε επιστρέφουμε αμέσως γιατί δεν αυξήθηκε κανείς καταχωρητής.
	//    -    Αν υπάρχουν εντολές αύξησης KAI εντολές max counter, προχωράμε στο βασικό κομάτι του προγράμματος

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

		//    Στο σημείο αυτό ξέρουμε ότι υπάρχουν ΚΑΙ εντολές αύξησης ΚΑΙ εντολές max counter.
		//    Αρχικά, βρίσκουμε με τον αλγόριθμο find_if την πρώτη τιμή του πίνακα που αυξάνει κάποιο καταχωρητή, και θέτουμε επαναλήπτες αρχής (bg) και τέλους (nd) στην τιμή του.
		//    Ο λόγος είναι ότι εντολές max counter στην αρχή του πίνακα πρακτικά δεν κάνουν τίποτα.
		//
		//    Στη συνέχεια ξεκινάμε ένα βρόγχο στον επαναλήπτη nd. Όταν αυτός γίνει ίσος με A.end() χρησιμοποιούμε break για να τερματίσουμε το βρόγχο.
		//    Με τον αλγόριθμο find_if εντοπίζουμε την πρώτη εντολή max counter στο διάστημα [bg,A.end()] και την αναθέτουμε στο nd.
		//    Δημιουργούμε τα unordered_set/unordered_multiset s, s1, τοποθετώντας σε αυτά όλα τα στοιχεία από [bg,nd].
		//    Πχ, στο παράδειγμά μας, θα βάλουμε στα σετ τα στοιχεία 3,4,4 που βρίσκονται πριν το πρώτο 6.
		//
		//    -    Αν τα σετ είναι κενά, έχουμε διαδοχικές εντολές max counter. Στην περίπτωση αυτή απλά αυξάνουμε τα bg, nd, καθώς δεν αλλάζει κάτι άλλο.
		//        Αν η περίπτωση αυτή δεν ληφθεί υπόψιν καταλήγουμε σε ατέρμονα βρόγχο, γιατί η αναζήτηση με την find_if θα έβρισκε συνέχεια το πρώτο στοιχείο (bg).
		//        Στο παράδειγμα με το σετ 3, 1, 6, 6, 1, 4, 4, θα έτρεχε η πρώτη επανάληψη στα 3,1, και στην επόμενη το bg θα άρχιζε δείχνοντας στο δεύτερο 6. Η νεα find_if θα εντόπιζε πάλι 
		//    το ίδιο στοιχείο.
		//    -    Αν τα σετ έχουν στοιχεία, με ένα range for στο s αναζητούμε την μέγιστη πολλαπλότητα των στοιχείων στο s2 (local), την οποία και προσθέτουμε στο mx.
		//
		//    Στην επόμενη επανάληψη θέλουμε να ψάξουμε τα στοιχεία που ακολουθούν μετά το nd. Έτσι, πρέπει να αλλάξουμε την τιμή του bg για να δείχνει στο επόμενο στοιχείο από το τρέχον nd.
		//    Αυτό το πετυχαίνουμε με ένα if στην αρχή του βρόγχου που ελέγχει αν οι τιμές των nd, bg ταυτίζονται. Αυτό συμβαίνει μόνο στην πρώτη επανάληψη ή όταν εντοπιστούν διαδοχικά max counter.
		//    Σε κάθε επόμενη επανάληψη όμως, θέλουμε να επαναπροσδιορίσουμε τα όρια κατάλληλα.
		//
		//    Όταν εντοπιστεί το τελευταίο max counter, τερματίζεται ο βρόγχος, και γεμίζουμε τον πίνακα των μετρητών b με την τιμή mx.
		//    Χρησιμοποιούμε την τιμή του bg που δείχνει στο επόμενο στοιχείο του Α, για να ξεκινήσουμε ένα βρόγχο από το στοιχείο αυτό μέχρι το τέλος του Α,
		//    Σε κάθε επανάληψη αυξάνουμε την αντίστοιχη τιμη στο b, και το επιστρέφουμε μετά το τέλος της επανάληψης.
		//
		//     Στο τρέχον παράδειγμα, αρχικά τα nd, bg δείχνουν στο στοιχείο Α[0]=3
		//    Την πρώτη φορά που θα τρέξει ο βρόγχος θέλουμε να ελέγξουμε τα στοιχεία 3,4,4, τα οποία βρίσκονται πριν το 6.
		//    Αν υπήρχε άλλη επανάληψη θα θέλαμε να ελέγξει τα στοιχεία 1,4,4 που ακολουθούν μετά το 6.
		//    Ο λόγος είναι ότι στην ε

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