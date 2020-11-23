/*
	[����] 2048 (Easy)
		���� ��ó : https://www.acmicpc.net/problem/12100
		Ÿ�� : ����
		�ݷ� : https://www.acmicpc.net/board/view/24061
*/

#include <iostream>
#include <vector>
#include <queue>

int answer = 2;
int N = 0;

std::vector<std::vector<int>> UpMove(std::vector<std::vector<int>> vec)
{
	std::queue<int> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vec[j][i] != 0)
			{
				q.push(vec[j][i]);
				vec[j][i] = 0;
			}
		}

		int index = 0;
		while (!q.empty())
		{
			int next_data = q.front();
			q.pop();

			if (vec[index][i] == 0)
				vec[index][i] = next_data;
			else if (vec[index][i] == next_data)
			{
				vec[index][i] *= 2;
				if (vec[index][i] > answer)
					answer = vec[index][i];
				index++;
			}
			else
				vec[++index][i] = next_data;
		}
	}

	return vec;
}

std::vector<std::vector<int>> DownMove(std::vector<std::vector<int>> vec)
{
	std::queue<int> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j >=0; j--)
		{
			if (vec[j][i] != 0)
			{
				q.push(vec[j][i]);
				vec[j][i] = 0;
			}
		}

		int index = N-1;
		while (!q.empty())
		{
			int next_data = q.front();
			q.pop();

			if (vec[index][i] == 0)
				vec[index][i] = next_data;
			else if (vec[index][i] == next_data)
			{
				vec[index][i] *= 2;
				if (vec[index][i] > answer)
					answer = vec[index][i];
				index--;
			}
			else
				vec[--index][i] = next_data;
		}
	}

	return vec;
}

std::vector<std::vector<int>> RightMove(std::vector<std::vector<int>> vec)
{
	std::queue<int> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j >= 0; j--)
		{
			if (vec[i][j] != 0)
			{
				q.push(vec[i][j]);
				vec[i][j] = 0;
			}
		}

		int index = N - 1;
		while (!q.empty())
		{
			int next_data = q.front();
			q.pop();

			if (vec[i][index] == 0)
				vec[i][index] = next_data;
			else if (vec[i][index] == next_data)
			{
				vec[i][index] *= 2;
				if (vec[i][index] > answer)
					answer = vec[i][index];
				index--;
			}
			else
				vec[i][--index] = next_data;
		}
	}

	return vec;
}

std::vector<std::vector<int>> LeftMove(std::vector<std::vector<int>> vec)
{
	std::queue<int> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vec[i][j] != 0)
			{
				q.push(vec[i][j]);
				vec[i][j] = 0;
			}
		}

		int index =0;
		while (!q.empty())
		{
			int next_data = q.front();
			q.pop();

			if (vec[i][index] == 0)
				vec[i][index] = next_data;
			else if (vec[i][index] == next_data)
			{
				vec[i][index] *= 2;
				if (vec[i][index] > answer)
					answer = vec[i][index];
				index++;
			}
			else
				vec[i][++index] = next_data;
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
���� ���̽�

5

2 2 4 8 16	

0 0 0 0 0

0 0 0 0 0

0 0 0 0 0

2 2 4 8 16

=>64

���� -> +1, -1ĭ�� �ƴ϶� 0�� �ƴ� ����ĭ.

*/

/*
	[���� ����]
		2020.11.23.	���۸����� �迭�� ������ ��ȸ�ϴ� ����� �ƴ� queue�� �̿��� ����� ã��. N^3���� N^2�� ȿ�����̶�� ����.
*/