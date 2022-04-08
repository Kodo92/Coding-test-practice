/*
	[백준 1976] 여행가자
		출처 : https://www.acmicpc.net/problem/1976
		풀이일 : 2022.03.22
*/

#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<int>& parents, const std::vector<std::vector<int>>& paths, std::vector<bool>& isVisited, const int startIdx) {

	std::queue<int> q;
	q.push(startIdx);
	isVisited[startIdx] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : paths[now]) {
			if (isVisited[next]) continue;
			isVisited[next] = true;
			q.push(next);
			parents[next] = startIdx;
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N,M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> paths(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
				paths[i].push_back(j);
		}
	}

	//disjoint set
	std::vector<int> parents(N);
	for (size_t i = 0; i < N; i++)
		parents[i] = i;

	std::vector<int> travleRoute(M);
	for (size_t i = 0; i < M; i++) {
		std::cin >> travleRoute[i];
		travleRoute[i] -= 1;
	}

	std::vector<bool> isVisited(N);

	for (size_t i = 0; i < N; i++)
	{
		if(!isVisited[i])
			BFS(parents, paths, isVisited, i);
	}

	int rootIdx = parents[travleRoute[0]];
	for (size_t i = 0; i < M; i++)
	{
		if (parents[travleRoute[i]] != rootIdx) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";

	return 0;
}

