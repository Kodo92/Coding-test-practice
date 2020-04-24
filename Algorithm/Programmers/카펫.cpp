#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	map<int, int> Divisors;

	int Sum = brown + red;
	for (int i = 3; i*i <= Sum; i++)
	{
		if (Sum % i == 0)
			Divisors[i] = Sum / i;
	}

	for (auto i : Divisors)
	{
		if(i.first > i.second || red % (i.first-2) != 0||(red/(i.first-2)) >= i.second)
			Divisors.erase(i.first);
	}
	answer.push_back(Divisors.begin()->second);
	answer.push_back(Divisors.begin()->first);
	return answer;
}

void main()
{
	solution(10, 2);
	solution(8, 1);
	solution(24, 24);
	solution(136, 1089);
}

/*
Point!
- Brown + Red�� ������� ������ ����
- ���� <= ���� 
- Red / ����-2 < ����
- Red % ����-2 == 0
- ����-2�� ���� : ������ ���� �ѷ��ΰ� �����ϱ�.
*/