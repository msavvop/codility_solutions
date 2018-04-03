/*
LESSON 5:Prefix sums

CountDiv




SCORE 100%

*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>

using std::cout;
using std::endl;
using std::vector;
using std::function;





int solution(int A, int B, int K)
{
	//100%
	int CountDiv, modulus, modulus2;
	CountDiv = (abs(A - B) + 1) / K;
	modulus = abs(A - B) % K;
	modulus2 = A%K;
	if (((modulus2 + modulus) == 0) && (K != 1)) CountDiv++;
	// όταν τα δύο υπόλοιπα αθροίζουν μηδέν τότε τα δύο όρια διαιρούνται οπότε πρέπει στο πηλίκο να προσθέσουμε άλλο ένα γιατί το πηλίκο μετράει μόνο το ένα όριο. 
	//πχ από 2-6 δυά 2.¨: (6-2)/2=2 ενώ διαιρούνται τ0 2 το 4 και το 6 άρα 3 και όχι 2.
	if (((modulus2 + modulus > K)) && (((abs(A - B) + 1) % K) != 0)) CountDiv++;
	//όταν τα δύο υπόλοιπα αθροίζουν πάνω από το διαιρέτη τότε έχεις ακόμα μια φορά μπου πρέπει να προστεθεί 
	//εκτός αν μετρήθηκε επειδή αυξήσαμε στην αρχή το Α-Β κατά 1 πριν βρούμε το πηλίκο


	return CountDiv;
}

int main(void)
{
	int A = 2;
	int B = 9;
	int K = 4;
	int CountDiv = solution(A, B, K);

	cout << CountDiv << "\t";


	cout << endl;
	return 0;
}