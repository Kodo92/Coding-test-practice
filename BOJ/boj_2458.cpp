/*
	[백준] 키 순서
		문제 출처 : https://www.acmicpc.net/problem/2458
		풀이 분류 : DFS
*/

#include <iostream>
#include <vector>

int DFS(const int num, const int in, const std::vector<std::vector<int>>& connections, std::vector<std::pair<int,int>>& counts)
{
	counts[num].first += in;
	for (auto i : connections[num])
		counts[num].second += DFS(i, in + 1, connections, counts);

	if (counts[num].second == 0)
		return 1;
	else
		return counts[num].second;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N,M;
	std::cin >> N>>M;

	std::vector<std::vector<int>> connections(N);
	std::vector <std::pair<int, int> > counts(N, { 0,0 });

	for (int i = 0; i < M; i++)
	{
		int left, right;
		std::cin >> left >> right;
		left -= 1;
		right -= 1;
		connections[left].push_back(right);
	}

	for (int i = 0; i < N; i++)
	{
		if (counts[i].first != 0)
			continue;
		DFS(i, 0, connections, counts);
	}

	int answer=0;
	for (int i = 0; i < N; i++)
	{
		if (counts[i].first + counts[i].second == N)
			answer++;
	}

	std::cout << answer;
	return 0;
}