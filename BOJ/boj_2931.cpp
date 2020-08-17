/*
	[백준] 2931 가스관
		문제 출처 : https://www.acmicpc.net/problem/2931

	[풀이 방법] 구현, 완전 탐색
		1. 유럽 전체를 순회하면서 '.'이면서 연결되는 관이 있는 경우를 찾는다.
		2. 연결되는 관이 존재하면 벡터에 좌표기준 관의 위치를 넣는다.
		3. 벡터의 값이 0이 아닌 경우 그에 맞는 관을 삽입해준다.
			- 가스흐름이 유일한 경우만 입력으로 주어지므로 vec에 값이 차는 '.' 좌표는 오직 1개이다.

		[실패 과정]
			1. BFS를 이용해 풀었는데 방향에 따라 Y,X 값 구해서 이동하는 부분에서 예외처리가 틀린 부분이 있었디.
				왠지는 더 찾아봐야겠다. -> 손절.

*/

#include <iostream>
#include <vector>
#include <queue>

int R, C;

std::vector<std::vector<char>> pipes{ {'|','+','1','4'},{ '|','+','2','3' } ,{ '-','+','1','2' } ,{ '-','+','3','4' } };
std::pair<int, int> movePosition[]{ {-1,0},{1,0},{0,-1},{0,1} };

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> R >> C;
	std::vector<std::vector<char>> board(R, std::vector<char>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			std::cin >> board[i][j];
	}

	std::vector<int> vec;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					int newY = i + movePosition[k].first;
					int newX = j + movePosition[k].second;
					if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
					if (board[newY][newX] == '.') continue;
					for (int z = 0; z < 4; z++)
						if (board[newY][newX] == pipes[k][z])
							vec.push_back(k);
				}
				if (!vec.empty())
				{
					std::cout << i + 1 << ' ' << j + 1 << ' ';
					if (vec.size() == 4)
					{
						std::cout << '+';
						return 0;
					}
					if (vec.size() == 2)
					{
						if (vec[0] == 0)
						{
							if (vec[1] == 1) std::cout << '|';
							else if (vec[1] == 2) std::cout << '3';
							else if (vec[1] == 3) std::cout << '2';
						}
						else if (vec[0] == 1)
						{
							if (vec[1] == 0) std::cout << '|';
							else if (vec[1] == 2) std::cout << '4';
							else if (vec[1] == 3) std::cout << '1';
						}
						else if (vec[0] == 2)
						{
							if (vec[1] == 0) std::cout << '3';
							else if (vec[1] == 1) std::cout << '4';
							else if (vec[1] == 3) std::cout << '-';
						}
						else if (vec[0] == 3)
						{
							if (vec[1] == 0) std::cout << '2';
							else if (vec[1] == 1) std::cout << '1';
							else if (vec[1] == 3) std::cout << '-';
						}
						return 0;
					}
				}
			}
		}
	}
	return 0;
}