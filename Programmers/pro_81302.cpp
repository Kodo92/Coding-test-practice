/*
	[프로] 거리두기 확인하기
		출처 : https://programmers.co.kr/learn/courses/30/lessons/81302
*/

#include <iostream>
#include <string>
#include <vector>

int getManhattanDistance(const std::pair<int, int> source, const std::pair<int, int> dest) {
	return abs(source.first - dest.first) + abs(source.second - dest.second);
}

bool checkPartition(const std::vector<std::string>& map, const int yPos, const int xPos) {
	return (map[yPos][xPos] == 'O') ? true : false;
}

bool checkViolation(const std::vector<std::string>& map, const std::pair<int, int> source, const std::pair<int, int> dest) {
	int dirY = dest.first - source.first, dirX = dest.second - source.second;
	if (dirX != 0) {
		if (dirX < 0)
		{
			if (checkPartition(map, source.first, source.second - 1))
				return true;
		}
		else
		{
			if (checkPartition(map, source.first, source.second + 1))
				return true;
		}
	}

	if (dirY != 0) {
		if (dirY < 0)
		{
			if (checkPartition(map, source.first - 1, source.second))
				return true;
		}
		else
		{
			if (checkPartition(map, source.first + 1, source.second))
				return true;
		}
	}
	return false;
}

std::vector<int> solution(std::vector<std::vector<std::string>> places) {
	std::vector<int> answer;
	for (int testCase = 0; testCase < places.size(); testCase++) {
		bool isViolation = false;
		std::vector<std::pair<int, int>> pPosition;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (places[testCase][i][j] == 'P')
					pPosition.push_back({ i,j });
			}
		}

		for (int i = 0; i < pPosition.size(); i++) {
			if (isViolation) break;
			for (int j = i + 1; j < pPosition.size(); j++) {
				int manhattanDistance = getManhattanDistance(pPosition[i], pPosition[j]);
				if (manhattanDistance == 2) {
					if (checkViolation(places[testCase], pPosition[i], pPosition[j])) {
						isViolation = true;
						break;
					}
				}
				else if (manhattanDistance == 1) {
					isViolation = true;
					break;
				}
			}
		}

		if (isViolation)
			answer.push_back(0);
		else
			answer.push_back(1);


	}
	return answer;
}

int main()
{
	solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
	return 0;
}

/*
	distance <= 2 ? -> distance == 2 & distance == 1
*/