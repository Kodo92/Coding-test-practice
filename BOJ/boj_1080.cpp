/*
	[백준 1080] 행렬
		출처 : https://www.acmicpc.net/problem/1080
*/

#include <iostream>
#include <vector>
#include <string>

void transfer(std::vector<std::string>& map, const int y, const int x) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[y+i][x+j] = (map[y+i][x+j] == '0') ? '1' : '0';
		}
	}
}

bool isSame(int N, std::vector<std::string>& A, std::vector<std::string>& B) {
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i])
			return false;
	}
	return true;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<std::string>> map(2, std::vector<std::string>(N));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}

	bool isEnd = false;
	int answer = 0;
	for (int i = 0; i < N && isEnd == false; i++) {
		for (int j = 0; j < M && isEnd == false; j++) {
			if (map[0][i][j] != map[1][i][j]) {
				if (i > N - 3 || j > M - 3) {
					isEnd = true;
					break;
				}
				transfer(map[0], i, j);
				answer++;
			}
		}
	}

	if (isSame(N,map[0],map[1]))
		std::cout << answer;
	else
		std::cout << -1;


	return 0;
}

