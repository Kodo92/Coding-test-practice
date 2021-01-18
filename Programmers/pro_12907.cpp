/*
	[프로] 거스름돈
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12907
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> money) {
	sort(money.begin(), money.end());
	vector<int> answer(n + 1,0);
	answer[0] = 1;
	for (int i = 0; i <= n; i++)
		if (i % money[0] == 0) answer[i] = 1;

	for (int i = 1; i < money.size(); i++)
	{
		for (int j = money[i]; j <= n; j++)
			answer[j] = (answer[j] + answer[j - money[i]]) % MOD;
	}

	return answer[n];
}

int main()
{
	cout << solution(5, { 1,2,5 }) << endl;
	return 0;
}