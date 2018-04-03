/*
Lesson 7: Stacks and Queues



100%

*/


#include <stack>
#include <iostream>
#include <vector>

using std::stack;
using std::vector;
using std::cout;
using std::endl;

int solution(vector <int> &H)
{
	//100%
	int count = 0;
	stack <int> wall;
	wall.push(0);

	for (int h : H)
	{
		while ((!wall.empty()) && (wall.top() >h))
		{
			wall.pop();

		}
		//Αδειάζεις όλα όσα είναι μεγαλύτερα του h μεχρι να βρεις ένα μικρότερο ή ίσο. Όχι μόνο την τρέχουσα κορυφή του stack. While δηλαδή για το άδειασμα και όχι if.
		// στο ίσο δεν κάνεις τίποτα. Συνεχίζεται δηλαδή το block μέχρι να βρείς ένα h μικρότερο όπότε κλείνει το block. Κλέινεις έτσι όλα τα block που έχουν ύψος μεγαλύτερο του h.
		//Μετράς τα καινούργια block (h>wall.top()) Σε μερικά h τρέχει και η while και η if, γιατί φεύγει ένα (ή περισσότερα) μπλοκ με  stack.top() μεγαλύτερο του h και το καινούργιο stack.top() 
		// μετά την while είναι μικρότερο οπότε τρέχει και η if. 

		if ((wall.empty()) || (wall.top() < h))
		{

			wall.push(h);
			count++;
		}
	}

	return count;
}

int main(void)
{
	vector <int> H = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	cout << solution(H) << endl;
	return 0;

}