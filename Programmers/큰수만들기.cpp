#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	auto startIter = number.begin();
	for (int i = number.size() - k-1; i >= 0 && startIter != number.end(); i--)
	{
		startIter = max_element(startIter, number.end() - i);
		answer += *startIter;
		startIter++;
	}

	return  answer;
}

// �ٸ���� �ڵ� ����
/*
string solution(string number, int k) {
	string answer = "";
	answer = number.substr(k);
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}
			else {
				break;
			}
		} while (1);
	}



	return answer;
}
*/
void main()
{
	cout << solution("4177252841",4);
}
/*
K���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ѵ�.
�߿��� ���� �Է¹��� ���ڿ��� ������ ��������Ѵ�. -> SORT() �� �� N�ڸ� �� ������ �ƴ�.
- POINT
N��° �ڸ����� ������ N���� ������ ���ڵ� �� ���� ū ���̴�. 
Ž���� �������� I+1��° �ڸ��� (I < K)�� ���� ���� ���������̴�.
*/