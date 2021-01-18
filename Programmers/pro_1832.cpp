/*
	[����] ������ õ��
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/1832
		��� : 2017 īī�� �ڵ� ����
*/

#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
	vector<vector<int>> right(m, vector<int>(n, 0));
	vector<vector<int>> down(m, vector<int>(n, 0));

	right[0][0] = down[0][0] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (city_map[i][j] == 0)
			{
				int prevRight = j - 1;
				int prevDown = i - 1;
				if (prevRight > -1)
					right[i][j] = (right[i][j] + right[i][prevRight]) % MOD;
				if (prevDown > -1)
					right[i][j] = (right[i][j] +  down[prevDown][j]) %MOD;
				down[i][j] = right[i][j];
			}
			else if (city_map[i][j] == 1)
				right[i][j] = down[i][j] = 0;
			else if (city_map[i][j] == 2)
			{
				int prevRight = j - 1;
				int prevDown = i - 1;
				if (prevRight > -1)
					right[i][j] = (right[i][j]+ right[i][prevRight]) % MOD;
				if (prevDown > -1)
					down[i][j] = (down[i][j] +  down[prevDown][j]) % MOD;
			}
		}
	}
	return right[m-1][n-1];
}

int main()
{
	//cout << solution(3, 3, { {0,0,0},{0,0,0},{0,0,0} }) << endl;
	cout << solution(3, 6, { {0, 2, 0, 0, 0, 2},{0, 2, 0, 0, 0, 2},{1, 0, 0, 2, 2, 0} }) << endl;


	return 0;
}