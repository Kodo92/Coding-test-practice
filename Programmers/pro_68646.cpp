/*
	[����] ǳ�� ��Ʈ����
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/68646
		��� : ���� �ڵ� ç���� ����1 - 9��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
	int answer = 0;

	vector<pair<int, int>> min(a.size(), {a.front(),a.back()});
	for (int i = 1; i < a.size(); i++)
		min[i].first = (a[i] < min[i - 1].first) ? a[i] : min[i - 1].first;

	for (int i = a.size()-2; i >= 0; i--)
		min[i].second = (a[i] < min[i + 1].second	) ? a[i] : min[i + 1].second;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > min[i].first && a[i] > min[i].second)
			continue;
		answer++;
	}
	return answer;
}

int main()
{
	cout << solution({9,-1,-5}) << endl;
}