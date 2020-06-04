#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	vector<int> distances(n + 1);
	vector<bool> visited(n + 1, false);
	vector<vector<int>> graph(n + 1, vector<int>());
	queue<int> nodes;

	int maxDistance = 0;

	// Graph에 경로 입력
	for (const auto i : edge)
	{
		graph[i[0]].push_back(i[1]);
		graph[i[1]].push_back(i[0]);
	}

	// BFS를 이용해 끝 노드의 경로 찾기    
	nodes.push(1);
	visited[1] = true;
	distances[1] = 0;

	while (!nodes.empty())
	{
		auto value = nodes.front();
		nodes.pop();
		for (const int dest : graph[value])
		{

			if (visited[dest])
				continue;
			nodes.push(dest);
			visited[dest] = true;
			distances[dest] = distances[value] + 1;
			maxDistance = (maxDistance < distances[dest]) ? distances[dest] : maxDistance;
		}
	}
	// 가장 멀리 떨어진 노드 개수 세기
	int answer = 0;
	for (const int value : distances)
	{
		if (value == maxDistance)
			answer++;
	}
	return answer;
}