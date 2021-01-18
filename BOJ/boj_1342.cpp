/*
	[백준] 1342 행운의 문자열
		문제 출처 : https://www.acmicpc.net/problem/1342

	[풀이 방법0] 완전 탐색	// 80ms
		1. input으로 받은 문자열을 정렬 후 모든 조합을 해보면서 행운의 문자열인지 체크한다.

	[풀이 방법1] DFS + 백트래킹 // 680ms
		1. 입력받은 문자열의 종류와 갯수를 배열에 저장한다.
		2. DFS를 이용해 1글자씩 추가하면서 LUCKY한지 검사한다.
			- 만약 행운하지 않다면 리턴한다. (백 트래킹)
		=> 0번의 방법보다 1번의 방법이 시간이 더 오래걸리는 이유는 문자열을 조합하면서 체크하는 경우의 수가 더 많기 때문.

	[풀이 일자] 2020.08.11
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

	// 0번 완전 탐색
	std::sort(input.begin(), input.end());
	do
	{
		if (isLucky(input))
			answer++;
	} while (std::next_permutation(input.begin(), input.end()));
	
	// 1번 DFS
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