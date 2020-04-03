#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Normal�� �־��� ��� 30*30 + 30*30 = 1800���� ������ ���� -> 2n�� = n��
// Normal ver : Vector�� Iterator�� �̿�
//	max] 0.1ms / 3.93MB
/*
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int compareValue = 0;
	bool breakFlag = false;

	for (vector<int>::iterator lostIter = lost.begin(); lostIter != lost.end(); )
	{
		breakFlag = false;
		for (vector<int>::iterator reserveIter = reserve.begin(); reserveIter != reserve.end(); )
		{
			if ((*lostIter) == (*reserveIter))
			{
				reserve.erase(reserveIter);
				lost.erase(lostIter);
				breakFlag = true;
				break;
			}
			else
			{
				if (reserveIter != reserve.end()) reserveIter++;
			}
		}
		if (!breakFlag)
			lostIter++;
	}

	for (vector<int>::iterator lostIter = lost.begin(); lostIter != lost.end(); )
	{
		breakFlag = false;
		for (vector<int>::iterator reserveIter = reserve.begin(); reserveIter != reserve.end(); )
		{
			if ((*lostIter) - (*reserveIter) == 1 || (*lostIter) - (*reserveIter) == -1)
			{
				reserve.erase(reserveIter);
				lost.erase(lostIter);
				breakFlag = true;
				break;
			}
			else
			{
				if (reserveIter != reserve.end()) reserveIter++;
			}
		}
		if (!breakFlag)
			lostIter++;
	}

	answer = n - lost.size();
	return answer;
}
*/

// Normal ver 1 : Vector[]�� �̿�
//	max] 0.00ms / 3.91MB
/*
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int compareValue = 0;
	bool breakFlag = false;

	for (int i = 0; i < lost.size(); )
	{
		breakFlag = false;
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				reserve.erase(reserve.begin() + j);
				lost.erase(lost.begin() + i);
				breakFlag = true;
				break;
			}
		}
		!breakFlag ? i++ : i = 0;
	}

	for (int i = 0; i < lost.size(); )
	{
		breakFlag = false;
		for (int j = 0; j < reserve.size(); j++)
		{
			if (1 == (lost[i]- reserve[j]) || -1 == (lost[i] - reserve[j]))
			{
				reserve.erase(reserve.begin() + j);
				lost.erase(lost.begin() + i);
				breakFlag = true;
				break;
			}
		}
		!breakFlag?i++:i=0;
	}

	answer = n - lost.size();
	return answer;
}
*/

// Others�� �־��� ��� 30+30+30+30 = 120���� ������ ���� -> 4n = n
// ������ �л��� ��ȣ�� 0������ ������ ������ ������ �����.
// Others	:	�ٸ���� ����Ǯ��	(vector<int> student�� �������� -> �������� ����)
/*
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int> student((n+1));

	for (int i : reserve) student[i] += 1;
	for (int i : lost) student[i] += -1;
	for (int i = 1; i <= n; i++) {
		if (student[i] == -1) {
			if (student[i - 1] == 1)
				student[i - 1] = student[i] = 0;
			else if (student[i + 1] == 1)
				student[i] = student[i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (student[i] != -1) answer++;

	return answer;
}
*/

int main()
{
	vector<int> Lost{0,3,4};
	vector<int> Reserve{3,8,9};

	cout << solution(10, Lost, Reserve);
}

/*
Test case] 
	- 5,[3,9,10], [3,8,9]		=> 9
	- 3, [1], [3]				=> 2
	- 5, [2,4], [1,3,5]		=> 4
	- 5, [1,3,5], [2,4]		=> 5

	ù ��° test case�� �����ؾ��Ѵ�. 
*/