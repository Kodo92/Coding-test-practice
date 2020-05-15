#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ���ϼ� üũ
// parameter key�� ��Ʈ������ �̿��� ��� column���� �������� �˾Ƴ��ϴ�.
// column���� ���� string�� ��ģ���� map�� �̿��� �ߺ�Ȯ���� �մϴ�.
bool checkUnique(vector<vector<string>>& relation, int key)
{
	map<string, int> checker;
	vector<int> columnIndexs;

	for (int i = 0; i < relation.front().size(); i++)
	{
		// relation.front().size()�� 4�� ��� index���� : 0001, 0010, 0100, 1000�� �˴ϴ�.
		int index = 1 << i;

		// key�� 1�̰� index�� 1�̸� and ����� 0
		// key�� 6 (0110)�̸� index�� 2 (0010), 4 (0100) �϶� ��ȿ�մϴ�. 
		// �׷��� 2, 4 �� ��� column���� �������� {1,2}���� �� �� �ֽ��ϴ�.
		if ((key & index) == 0)
			continue;
		columnIndexs.push_back(i);
	}

	// relation���� ���� string�̹Ƿ�, map<string,int>�� �̿��� �ߺ�üũ�� ���ݴϴ�.
	for (auto& value : relation)
	{
		string str = "";
		// 1,2�� column���� �����̶�� 1,2,3�� column�� ������ �����ݴϴ�.
		// 100 / ryan / music / 2 => string str = "ryanmusic"
		for (auto i : columnIndexs)
			str += value[i];

		if (!checker[str])
			checker[str] = 1;
		else
			return false;
	}
	return true;
}

bool checkMinimality(vector<int>& candidates, int key)
{
	// ���� �ĺ�Ű�� ���� �Ķ���ͷ� ���� key�� ���ϴ��� Ȯ���մϴ�.
	// key : 11, candidates value : 6 �̶�� key�� 1110, value : 0110�Դϴ�. 
	// key & value = 6 �� ���� 11�� �κ��������� 6�� ������ �� �� �ֽ��ϴ�.
	for (auto value : candidates)
	{
		if ((key & value) == value)
			return false;
	}
	return true;
}

int solution(vector<vector<string>> relation) {

	vector<int> answer;

	for (int i = 1; i< (1 << relation.front().size()); i++)
	{
		if (checkUnique(relation, i) && checkMinimality(answer, i))
			answer.push_back(i);
	}

	return answer.size();
}

/*
��Ʈ ������ �̿��� ���� ����� �� ���.
and ������ �̿��� �ߺ� Ȯ��
*/