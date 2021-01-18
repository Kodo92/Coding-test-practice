#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());

	int average = M / budgets.size();

	if (budgets.front() >= M)
		return average;

	int sum = 0;
	for (int i = 0; i<budgets.size(); i++)
	{
		if (average < budgets[i])
			return average;

		sum += budgets[i];
		if (i + 1 == budgets.size() && sum <= M)
			return budgets.back();

		average = (M - sum) / (budgets.size() - (i + 1));

	}

	if (average > sum)
		return budgets.back();
}

/*
1. �����û ������ �������� ����
2. �� ������ ����� ����.
3. �ݺ����� ���鼭 �����û���� �հ�, ���� ������ ������ ���� ������ ����� ����.
4. ��հ��� �����û ������ ũ�� �ִ� ��.
5. �迭�� ������ ��ġ�� ���� ���� ��û���麸�� ����� �Ǵ�. -> ���� ��û��� ���� �� �� �� �ִ�.
*/