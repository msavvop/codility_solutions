/*
7. Stacks and Queues

Brackets


100 out of 100 points

*/

#include<string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
# include <stack>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::deque;
using std::stack;

int solution(string &S)
{
	//    100% 
	stack<char> a;
	//    Εδώ μπορούμε να χρησιμοποιήσουμε ένα stack από χαρακτήρες.
	//    Σαρώνουμε το διάνυσμα από την αρχή μέχρι το τέλος και κάθε φορά που βρίσκουμε χαρακτήρες ανοίγματος ({[ τους τοποθετούμε στη κορυφή του σωρού.

	//    Αντίστοιχα, κάθε φορά που βρίσκουμε χαρακτήρες κλεισίματος )}], απομακρύνουμε τον χαρακτήρα που βρίσκεται στην κορυφή.
	//    Κατά την απομάκρυνση πρέπει απαραίτητα να ελέγχουμε ποιός χαρακτήρας βρίσκεται στην κορυφή του σωρού. Αν πχ έχουμε να απομακρύνουμε παρένθεση
	//    και στην κορυφή του σωρού υπάρχει { ή [ τότε μπορούμε να σταματήσουμε την σάρωση της συμβολοσειράς και να επιστρέψουμε 0
	//    καθώς έχουμε εντοπίσει αταίριαστο ζεύγος {)...

	//    Αν στο τέλος της σάρωσης της συμβολοσειράς το μέγεθος του stack είναι 0, τα σύμβολα ()[]{} ζευγαρώνουν σε ορθή σειρά και επιστρέφουμε 1.

	for (int i = 0; i<S.size(); i++)
	{
		if (S[i] == '(' || S[i] == '{' || S[i] == '[')
			a.push(S[i]);
		else if (S[i] == ')')
		{
			if (a.size() == 0 || a.top() != '(') return 0;
			else a.pop();
		}
		else if (S[i] == ']')
		{
			if (a.size() == 0 || a.top() != '[') return 0;
			else a.pop();
		}
		else if (S[i] == '}')
		{
			if (a.size() == 0 || a.top() != '{') return 0;
			else a.pop();
		}
	}

	if (a.size() == 0)
		return 1;
	else
		return 0;
}
/*
int solution(string &S)
{
//    100% 
int count1{}, count2{}, count3{};

for (int i=0; i<S.size(); i++)
{
if (S[i]=='(')
count1++;
else if (S[i]==')')
{
count1--;
if (count1<0) return 0;
if ( S[i-1] == '[' || S[i-1]=='{') return 0;
}
else if (S[i]=='{')
count2++;
else if (S[i]=='}')
{
count2--;
if (count2<0) return 0;
if ( S[i-1] == '(' || S[i-1]=='[') return 0;
}
else if (S[i]=='[')
count3++;
else
{
count3--;
if (count3<0) return 0;
if ( S[i-1] == '(' || S[i-1]=='{') return 0;
}
}

if (count1==0 && count2==0 && count3==0)
return 1;
else
return 0;
}

*/

/*
deque<char> str(deque <char>&S)
{
//87%
char ch;
char lookfor;
int count = 0;


if (S.size() == 0) return S;
if (S.size() % 2 == 1) return S;

ch = S[0];



switch (ch)
{
case '(':
lookfor = ')';

break;


case '{':
lookfor = '}';


break;

case '[':
lookfor = ']';

break;

default:
return S;

}

for (auto iter = S.begin(); iter != S.end(); iter++)
{
if (*iter == ch) count++;
if (*iter == lookfor) count--;

if (*iter == lookfor&&count == 0)
{
if ((iter - 1 - S.begin()) % 2 == 1) return S;
S.erase(iter);
S.pop_front();



return  str(S);

}


}


return S;




}


int solution(string &S)
{
deque <char>A(S.length());
deque <char>B;


copy(S.begin(), S.end(), A.begin());

B = str(A);
if (B.size() == 0)
{
//		cout << A << endl;
return 1;

}
else
{
//		cout << A << endl;
return 0;

}



}
*/
/*
vector<char> str(vector <char>S)
{
//50%
char ch;
char lookfor;
int count = 0;
vector <char> A;
vector<char> B;
vector <char> C;
vector<char> D;

if (S.size() == 0) return S;
ch = S[0];

//	if (S.size() % 2 == 1) return S;

switch (ch)
{
case '(':
lookfor = ')';

break;


case '{':
lookfor = '}';


break;

case '[':
lookfor = ']';

break;

default:
return S;

}

for (auto iter=S.begin(); iter!=S.end(); iter++)
{
if (*iter == ch) count++;
if (*iter == lookfor) count--;

if (*iter == lookfor&&count == 0)
{
if( (iter-1 - S.begin()) % 2 == 1) return S;
S.erase(iter);
S.erase(S.begin());



return  str(S);

}


}


return S;




}


int solution(string &S)
{
vector <char>A;
vector <char>B;

if (S.length() % 2 == 1) return 0;
for (int i = 0; i < S.length(); i++)
{
A.push_back(S[i]);
}
//	copy(S.begin(), S.end(), A.begin());

B = str(A);
if (B.size() == 0)
{
//		cout << A << endl;
return 1;

}
else
{
//		cout << A << endl;
return 0;

}



}
*/
/*
string str(string S)
{
//75%
char ch;
char lookfor;
int count = 0;
string A;
string B;
string C;
string D;

ch = S[0];
if (S == "") return "";

switch (ch)
{
case '(':
lookfor = ')';

break;


case '{':
lookfor = '}';


break;

case '[':
lookfor = ']';

break;

default:
return S;

}

for (int i = 0; i < S.length(); i++)
{

if (S[i] == ch) count++;
if (S[i] == lookfor) count--;

if (S[i]==lookfor&&count == 0)
{
A = string(S, 1, i - 1);
B=str(A);
if (B.length() % 2 == 1) return B;

if (i < S.length()-1)
{
D = string(S, i+1, S.length() - 1);
C=str(D);
if (C.length() % 2 == 1) return C;

}
return str(B + C);



}

}
return S;




}


int solution(string &S)
{
string A;
if (S.length() % 2 == 1) return 0;

A = str(S);
if (A == "")
{
//		cout << A << endl;
return 1;

}
else
{
//		cout << A << endl;
return 0;

}



}
*/
int main(void)
{
	string  S = "{[([{)(}])]}";
	//	string  S = "{[()()]}";
	//	string  S = "([)()]";



	cout << solution(S) << endl;


	return 0;
}