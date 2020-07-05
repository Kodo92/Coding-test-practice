/*
	[백준] 14890 경사로
		문제 출처 : https://www.acmicpc.net/problem/14890

	[풀이 방법] : 완전 탐색
		1. 탐색하려는 줄의 높이 차를 계산한다.
			- 높이 차이가 1 이상이라면 return false;
			- 경사로를 놓을 같은 높이의 연속된 낮은 칸의 길이가 L보다 작은 경우 return false;
				- 탐색할 때 기준점의 높이가 높다/낮다 따로 체크해야합니다.
			- 경사로를 놓은 곳에 또 경사로를 놓는 경우

	[주의 사항]
		1. 경사로 놓은 곳에 또 경사로를 놓는 경우는 검사하는 줄의 경사로만 의미힌다. 
			-	가로와 세로에 경사로가 같은 위치에 놓이게 되는 경우는 경사로가 겹치는 경우가 아니다!
*/

#include <iostream>
#include <vector>

int N, L;
std::vector<std::vector<int>> map;

bool checkHorizon(const int index)
{
	std::vector<bool> isUsed (N,false);
	for (int i = 1; i < N; i++)
	{
		int diff = map[index][i] - map[index][i - 1];
		if (diff > 1 || diff < -1) return false;
		if (diff == 0) continue;
		
		// 높이 차이가 1인 경우 : i가 i-1보다 높다
		if (diff == 1)
		{
			// i-1 부터 -- 하면서 높이가 같은지 체크. -> L만큼 -- 하는데 그 전에 루프가 끝나면 return false
			int rangeIndex = i;
			int rangeHeight = map[index][i - 1];
			for (int j = i-1; j >= 0 && (i - j) <= L; j--)
			{
				if (map[index][j] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if (i - rangeIndex < L) return false;

			// 경사로 설치
			for (; rangeIndex != i; rangeIndex++)
				isUsed[rangeIndex] = true;
		}
		else
		{
			// 높이 차이가 -1인 경우 : i가 i-1보다 낮다
			int rangeIndex = i-1;
			int rangeHeight = map[index][i];
			for (int j = i; j < N && (j - (i - 1)) <= L; j++)
			{
				if (map[index][j] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if ((rangeIndex - (i - 1)) < L) return false;
			for (; rangeIndex >=  i; i++)
				isUsed[i] = true;
			i -= 1;
		}		
	}
	return true;
}

bool checkVertical(const int index)
{
	std::vector<bool> isUsed(N, false);
	for (int i = 1; i < N; i++)
	{
		int diff = map[i][index] - map[i-1][index];
		if (diff > 1 || diff < -1) return false;
		if (diff == 0) continue;

		// 높이 차이가 1인 경우 : i가 i-1보다 높다
		if (diff == 1)
		{
			// i-1 부터 -- 하면서 높이가 같은지 체크. -> L만큼 -- 하는데 그 전에 루프가 끝나면 return false
			int rangeIndex = i;
			int rangeHeight = map[i-1][index];
			for (int j = i - 1; j >= 0 && (i - j) <= L; j--)
			{
				if (map[j][index] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if (i - rangeIndex < L) return false;

			// 경사로 설치
			for (; rangeIndex != i; rangeIndex++)
				isUsed[rangeIndex] = true;
		}
		else
		{
			// 높이 차이가 -1인 경우 : i가 i-1보다 낮다
			int rangeIndex = i-1;
			int rangeHeight = map[i][index];
			for (int j = i; j < N && (j - (i - 1)) <= L; j++)
			{
				if (map[j][index] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if ((rangeIndex - (i - 1)) < L) return false;
			for (; rangeIndex >= i; i++)
				isUsed[i] = true;
			i -= 1;
		}
	}
	return true;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> L;

	map.resize(N);

	for (int i = 0; i < N; i++)
	{
		map[i].resize(N);
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (checkHorizon(i))
			answer++;
		if (checkVertical(i))
			answer++;

	}

	std::cout << answer;

}