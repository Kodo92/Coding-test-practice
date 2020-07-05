/*
	[백준] 1328 고층 빌딩
		문제 출처 : https://www.acmicpc.net/problem/1328

	[풀이 방법]
		풀이 참고 : https://ksj14.tistory.com/entry/BackJoon1328-%EA%B3%A0%EC%B8%B5-%EB%B9%8C%EB%94%A9
		점화식 : dp[n][l][r] = dp[n - 1][l][r] * (n - 2) + dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1]

		dp[1][1][1] = dp[2][2][1] = dp[2][1][2] = 1
		dp[n][1][n] = dp[n][n][1] = 1	-> 123, 321 이런 경우
		N : 3부터 N까지, L,R은 1부터 L,R까지

		dp의 자료형은 long long으로 해야한다.
		1000000007의 나머지 연산한 결과를 저장한다고 int를 할 수도 있지만.
		dp[n][l][r]의 값을 계산할 때 묵시적 형변환으로 int형 계산 결과가 리턴되기 때문이다.
*/

#include <iostream>

long long dp[101][101][101];

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, L, R;
	std::cin >> N >> L >> R;

	dp[1][1][1] = dp[2][2][1] = dp[2][1][2] = 1;

	for (int n = 3; n <= N; n++)
	{
		dp[n][n][1] = dp[n][1][n] = 1;
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				long long temp=0;
				temp = ((dp[n - 1][l][r] * (n - 2)) + dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1]);
				dp[n][l][r] = temp % 1000000007;
			}
		}
	}
	std::cout << dp[N][L][R];
}