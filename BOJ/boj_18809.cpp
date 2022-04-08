/*
	[백준] Gaaaaaaaaaarden
		출처 : https://www.acmicpc.net/problem/18809
		풀이일 : 2022.04.09.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M, G, R;

struct node {
	int type;
	int yPos;
	int xPos;
};

int dx[]{ 0,0,-1,1 };
int dy[]{ -1,1,0,0 };

bool isRange(const int newY, const int newX) {
	return !(newY < 0 || newY >= N || newX < 0 || newX >= M);
}

int BFS(std::vector<std::vector<int>>& garden, std::queue<node>& queue) {

	// R, G, F flag

	std::vector<std::vector<bool>> isVisited(N, std::vector<bool>(M, false));
	std::vector<std::vector<std::vector<int>>> isFertilize(N, std::vector<std::vector<int>>(M, std::vector<int>(3, 0)));
	std::vector<std::queue<node>> qVec(2, std::queue<node>());
	int qIdx = 0;
	qVec[qIdx] = queue;

	int flowerCount = 0;
	int cost = 0;
	while (!qVec[qIdx].empty()) {
		int nextIdx = (qIdx + 1) % 2;
		cost++;
		while (!qVec[qIdx].empty()) {
			node& now = qVec[qIdx].front();
			qVec[qIdx].pop();

			isVisited[now.yPos][now.xPos] = true;
			if (isFertilize[now.yPos][now.xPos][2] != 0) {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int newY = now.yPos + dy[i];
				int newX = now.xPos + dx[i];
				if (!isRange(newY, newX)) continue;
				if (garden[newY][newX] == 0) continue;
				if (isVisited[newY][newX]) continue;
				if (isFertilize[newY][newX][now.type] != 0) continue;

				if(now.type == 0)
					isFertilize[newY][newX][now.type] = cost;
				else 
					isFertilize[newY][newX][now.type] = cost * -1;

				if (isFertilize[newY][newX][(now.type + 1) % 2] == (isFertilize[newY][newX][now.type] * -1)) {
					isFertilize[newY][newX][2] = 1;
					flowerCount++;
					continue;
				}
				qVec[nextIdx].push({ now.type,newY,newX });
			}
		}
		qIdx = nextIdx;
	}
	return flowerCount;
}

int main() {


	std::cin >> N >> M >> G >> R;
	std::vector<std::vector<int>> garden(N, std::vector<int>(M));

	std::vector<std::pair<int, int>> possible;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> garden[i][j];
			if (garden[i][j] == 2)
				possible.push_back({ i,j });
		}
	}

	std::vector<int> permutation(possible.size(),0);
	int idx = permutation.size()-1;
	for (int i = 0; i < R; i++) {
		permutation[idx--] = 2;
	}

	for (int i = 0; i < G; i++) {
		permutation[idx--] = 1;
	}

	int answer = 0;
	do {
		std::queue<node> queue;
		for (int i = 0; i < permutation.size(); i++) {
			if (permutation[i] == 0) continue;
			queue.push({ permutation[i]-1,possible[i].first, possible[i].second });
		}
		int retval = BFS(garden, queue);
		answer = (answer < retval) ? retval : answer;
	} while (std::next_permutation(permutation.begin(), permutation.end()));

	std::cout << answer;

	return 0;
}