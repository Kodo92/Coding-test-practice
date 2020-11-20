/*
	[백준] 2048 (Easy)
		문제 출처 : https://www.acmicpc.net/problem/12100
		구현
		https://www.acmicpc.net/board/view/24061
*/

#include <iostream>
#include <vector>

int answer = 2;
int N = 0;

// return vec 버그.

std::vector<std::vector<int>> UpMove(std::vector<std::vector<int>> vec)
{
	bool isChange = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vec[j][i] !=0 && vec[j][i] == vec[j+1][i])
			{
				vec[j][i] *= 2;
				vec[j+1][i] = 0;
				if (answer < vec[j][i])
					answer = vec[j][i];
				isChange = true;
			}
		}
	}

	if (!isChange)
		return vec;

	// 칸 땡기기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vec[j][i] != 0) continue;

			for (int k = j+1; k <= N - 1; k++)
			{
				if (vec[k][i] == 0) continue;
				vec[j][i] = vec[k][i];
				vec[k][i] = 0;
				break;
			}
		}
	}

	return vec;
}

std::vector<std::vector<int>> DownMove(std::vector<std::vector<int>> vec)
{
	bool isChange = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j > 0 ; j--)
		{
			if (vec[j][i] != 0 && vec[j][i] == vec[j - 1][i])
			{
				vec[j][i] *= 2;
				vec[j - 1][i] = 0;
				if (answer < vec[j][i])
					answer = vec[j][i];
				isChange = true;
			}
		}
	}

	if (!isChange)
		return vec;

	// 칸 땡기기
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (vec[j][i] != 0) continue;

			for (int k = j - 1; k >= 0; k--)
			{
				if (vec[k][i] == 0) continue;
				vec[j][i] = vec[k][i];
				vec[k][i] = 0;
				break;
			}
		}
	}

	return vec;
}

std::vector<std::vector<int>> RightMove(std::vector<std::vector<int>> vec)
{
	bool isChange = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j > 0; j--)
		{
			if (vec[i][j] != 0 && vec[i][j] == vec[i][j - 1])
			{
				isChange = true;
				vec[i][j] *= 2;
				if (answer < vec[i][j])
					answer = vec[i][j];
				vec[i][j - 1] = 0;
			}
		}
	}

	if (!isChange)
		return vec;

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (vec[i][j] != 0) continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (vec[i][k] == 0) continue;
				vec[i][j] = vec[i][k];
				vec[i][k] = 0;
				break;
			}
		}
	}

	return vec;
}

std::vector<std::vector<int>> LeftMove(std::vector<std::vector<int>> vec)
{
	bool isChange = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vec[i][j] != 0 && vec[i][j] == vec[i][j + 1]) 
			{
				isChange = true;
				vec[i][j] *= 2;
				if (answer < vec[i][j])
					answer = vec[i][j];
				vec[i][j + 1] = 0;
			}
		}
	}

	if (!isChange)
		return vec;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vec[i][j] != 0) continue;
			for (int k = j + 1; k <= N - 1; k++)
			{
				if (vec[i][k] == 0) continue;
				vec[i][j] = vec[i][k];
				vec[i][k] = 0;
				break;
			}
		}
	}

	return vec;
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
		{
			std::cin >> vec[i][j];
			if (answer < vec[i][j])
				answer = vec[i][j];
		}
	}

	Recursive(1,vec);

	std::cout << answer;
	return 0;
}

/*
예외 케이스

5

2 2 4 8 16

0 0 0 0 0

0 0 0 0 0

0 0 0 0 0

2 2 4 8 16

=>64

개선 -> +1, -1칸이 아니라 0이 아닌 다음칸.

*/