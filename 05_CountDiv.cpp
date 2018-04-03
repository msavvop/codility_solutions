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
	// ���� �� ��� �������� ��������� ����� ���� �� ��� ���� ����������� ����� ������ ��� ������ �� ����������� ���� ��� ����� �� ������ ������� ���� �� ��� ����. 
	//�� ��� 2-6 ��� 2.�: (6-2)/2=2 ��� ����������� �0 2 �� 4 ��� �� 6 ��� 3 ��� ��� 2.
	if (((modulus2 + modulus > K)) && (((abs(A - B) + 1) % K) != 0)) CountDiv++;
	//���� �� ��� �������� ��������� ���� ��� �� �������� ���� ����� ����� ��� ���� ���� ������ �� ��������� 
	//����� �� ��������� ������ �������� ���� ���� �� �-� ���� 1 ���� ������ �� ������


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