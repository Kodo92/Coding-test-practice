/*
	[백준] 1937 욕심쟁이 판다 
		문제 출처 : https://www.acmicpc.net/problem/1937

	[풀이 방법] : DP & DFS
		1. DP는 0으로 초기화 한다.
		2. 만약 DP[x][y]가 0이 아니면 경로탐색된 경우이다. 바로 리턴해준다.
		2-1. 0이면 상하좌우 움직이면서 경로탐색을 한다.
			-> DFS를 이용하는 이유는 탐색하는 위치의 최댓값을 구한 다음 그 위치에 저장하기 때문! (재귀)


	[실패 과정]
		1. BFS를 이용해 각 위치마다 최대 생존일 수를 구했다. -> 시간초과.
		2. DP & 메모이제이션을 사용했다. -> 시간초과
			-> BFS가 아니라 DFS로 변경

	[풀이 일자] 2020.07.18
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 500;
int N, answer;
std::pair<int, int> dir[]{ {-1,0},{1,0},{0,-1},{0,1} };

int map[SIZE][SIZE];
int path[SIZE][SIZE];

int DFS(std::pair<int,int> source)
{
	if (path[source.first][source.second] != 0)
		return path[source.first][source.second];

	path[source.first][source.second] = 1;

	for (int i = 0; i < 4; i++)
	{
		std::pair<int, int> newPos = source;
		newPos.first += dir[i].first;
		newPos.second += dir[i].second;

		if (newPos.first < 0 || newPos.first >= N || newPos.second < 0 || newPos.second >= N) continue;
		if (map[source.first][source.second] < map[newPos.first][newPos.second])
			path[source.first][source.second] = std::max(path[source.first][source.second], DFS(newPos)+1);
	}
	return path[source.first][source.second];
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			answer = std::max(answer, DFS({ i,j }));
	}
	std::cout << answer;
	return 0;
}