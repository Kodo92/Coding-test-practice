/*
	[백준 1799] 비숍
		출처 : https://www.acmicpc.net/problem/1799
		풀이일 : 2022.04.04
*/

#include <iostream>
#include <vector>

int N;
int dir[][2] { {-1,-1},{1,-1},{-1,1},{1,1} };
int answer[2]{ 0,0 };

bool check(std::vector<std::vector<int>>& map, std::pair<int, int> pos) {
	for (int i = 0; i < 4; i++) {
		int yPos = pos.first, xPos = pos.second;
		while (true) {
			yPos += dir[i][0];
			xPos += dir[i][1];
			if (yPos < 0 || yPos >= N || xPos < 0 || xPos >= N) break;
			if (map[yPos][xPos] == 2)
				return false;
		}
	}
	return true;
}

void DFS(std::vector<std::vector<int>>& map, std::pair<int,int> pos, const bool odd, const int count) {
	if (pos.second >= N) {
		pos.first++;
		pos.second = (pos.second % 2 == 0) ? 1: 0;
	}
	if (pos.first >= N) {
		answer[odd] = (answer[odd] > count) ? answer[odd] : count;
		return;
	}

	// 비숍을 놓을 수 있는 경우
	if (map[pos.first][pos.second] == 1 && check(map, pos)) {
		map[pos.first][pos.second] = 2;
		DFS(map, { pos.first, pos.second + 2 }, odd, count + 1);
		map[pos.first][pos.second] = 1;
	}
	DFS(map, { pos.first, pos.second + 2 }, odd, count);
}

int main() {
	
	std::cin >> N;
	std::vector<std::vector<int>> map(N,std::vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}

	}

	DFS(map, { 0,0 }, false, 0);
	DFS(map, { 0,1 }, true, 0);

	std::cout << answer[0] + answer[1];
	return 0;
}