/*
	[����] 2606 ���̷���
		���� ��ó : https://www.acmicpc.net/problem/2606

	[Ǯ�� ���] : �÷��̵�-�ͼ� 
*/

#include <iostream>
#include <vector>

const int INF = 2147483647;
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N,M;
	std::cin >> N>>M;

	std::vector<std::vector<bool>> vec(N + 1, std::vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++)
		vec[i][i] = 0;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;
		vec[A][B] = true;
		vec[B][A] = true;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <=N; i++) {
			for (int j = 1; j <= N; j++) {
				if (vec[i][k] && vec[k][j]) vec[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (vec[1][i]) cnt++;
	}


	return 0;
}