/*
	[����] 1342 ����� ���ڿ�
		���� ��ó : https://www.acmicpc.net/problem/1342

	[Ǯ�� ���0] ���� Ž��	// 80ms
		1. input���� ���� ���ڿ��� ���� �� ��� ������ �غ��鼭 ����� ���ڿ����� üũ�Ѵ�.

	[Ǯ�� ���1] DFS + ��Ʈ��ŷ // 680ms
		1. �Է¹��� ���ڿ��� ������ ������ �迭�� �����Ѵ�.
		2. DFS�� �̿��� 1���ھ� �߰��ϸ鼭 LUCKY���� �˻��Ѵ�.
			- ���� ������� �ʴٸ� �����Ѵ�. (�� Ʈ��ŷ)
		=> 0���� ������� 1���� ����� �ð��� �� �����ɸ��� ������ ���ڿ��� �����ϸ鼭 üũ�ϴ� ����� ���� �� ���� ����.

	[Ǯ�� ����] 2020.08.11
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int size;
int answer;

bool isLucky(std::string checked)
{
	if (checked.size() == 0)
		return true;
	for (int i = 0; i < checked.size() - 1; i++)
	{
		if (checked[i] == checked[i + 1])
			return false;
	}
	return true;
}

void dfs(std::vector<std::pair<char, int>> vec, int count, std::string str)
{
	if (!isLucky(str))
		return;

	if (count == size)
	{
		answer++;
		return;
	}

	for (auto& i : vec)
	{
		if (i.second != 0)
		{
			i.second--;
			dfs(vec, count + 1, str + i.first);
			i.second++;
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::string input;
	std::cin >> input;

	// 0�� ���� Ž��
	std::sort(input.begin(), input.end());
	do
	{
		if (isLucky(input))
			answer++;
	} while (std::next_permutation(input.begin(), input.end()));
	
	// 1�� DFS
	size = input.size();
	std::vector<std::pair<char, int>> vec;
	for (const auto& i : input)
	{
		bool isFind = false;
		for (auto& j : vec)
		{
			if (j.first == i)
			{
				isFind = true;
				j.second++;
				break;
			}
		}
		if(!isFind)
			vec.push_back({ i,1 });
	}

	dfs(vec,0, "");

	std::cout << answer;

	return 0;
}