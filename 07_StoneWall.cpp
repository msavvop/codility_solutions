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
		//��������� ��� ��� ����� ���������� ��� h ����� �� ����� ��� ��������� � ���. ��� ���� ��� �������� ������ ��� stack. While ������ ��� �� �������� ��� ��� if.
		// ��� ��� ��� ������ ������. ����������� ������ �� block ����� �� ����� ��� h ��������� ����� ������� �� block. �������� ���� ��� �� block ��� ����� ���� ���������� ��� h.
		//������ �� ���������� block (h>wall.top()) �� ������ h ������ ��� � while ��� � if, ����� ������ ��� (� �����������) ����� ��  stack.top() ���������� ��� h ��� �� ���������� stack.top() 
		// ���� ��� while ����� ��������� ����� ������ ��� � if. 

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