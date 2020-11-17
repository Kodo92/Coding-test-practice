/*
	[백준] 2048 (Easy)
		문제 출처 : https://www.acmicpc.net/problem/12100
		구현
*/

#include <iostream>
#include <vector>

int answer = 0;
int N = 0;

std::vector<std::vector<int>>& UpMove(std::vector<std::vector<int>> vec)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 2; j++)
		{
			if (vec[i][j] !=0 && vec[i][j] == vec[i][j + 1])
			{
				vec[i][j] *= 2;
				vec[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 2; j++)
		{
			if (vec[i][j] != 0 && vec[i][j] == vec[i][j + 1])
			{
				vec[i][j] *= 2;
				vec[i][j + 1] = 0;
			}
		}
	}
}

std::vector<std::vector<int>>& DownMove(std::vector<std::vector<int>> vec)
{

}

std::vector<std::vector<int>>& RightMove(std::vector<std::vector<int>> vec)
{

}

std::vector<std::vector<int>>& LeftMove(std::vector<std::vector<int>> vec)
{

}


void Recursive(int count, std::vector<std::vector<int>> vec)
{
	if (count >5)
		return;

	Recursive(count + 1, UpMove(vec));
	Recursive(count + 1, DownMove(vec));
	Recursive(count + 1, RightMove(vec));
	Recursive(count + 1, LeftMove(vec));
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	std::vector<std::vector<int>> vec(N, std::vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> vec[i][j];
	}

	Recursive(1,vec);
	return 0;
}