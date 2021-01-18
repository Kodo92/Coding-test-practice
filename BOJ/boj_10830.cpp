/*
	[백준] 10830 행렬 제곱
		문제 출처 : https://www.acmicpc.net/problem/10830

	[풀이 방법] 구현
		1. 행렬의 곱셈 공식을 구글링한다. (A를 B번 곱하는 것)
		2. 구현한다.

	[실패 과정]
		1. B만큼 루프를 돌면서 하나하나 계산 : 시간초과
			-> 4제곱은 (2+2)
		2. 런타임 에러 5*5 배열을 100,000,000,000 크기만큼 선언하면 메모리 터짐.
	[풀이 일자] 2020.08.04
*/

#include <iostream>
#include <vector>

long long N, B;

std::vector<std::vector<int>> power(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
	std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += (a[i][k] * b[k][j]);
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

std::vector<std::vector<int>> dfs(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &v, long long square) {
	if (square == 1) return v;
	std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));
	if (square % 2 == 0) {
		temp = dfs(a, v, square / 2);
		return power(temp, temp);
	}
	temp = dfs(a, v, square - 1);
	return power(temp, a);
}
int main()
{
	std::cin >> N >> B;
	std::vector<std::vector<int>> input(N,std::vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> input[i][j];

	std::vector<std::vector<int>> answer = input;
	
	answer = dfs(answer, input, B);

	for (const auto& i : answer)
	{
		for (const auto j : i)
			std::cout << j % 1000<< ' ';
		std::cout << '\n';
	}
	return 0;
}