/*
	[백준] 피보나치 수
		문제 출처 : https://www.acmicpc.net/problem/2747
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> answer(n+1);
    answer[0] = 0;
    answer[1] = 1;

    for (int i = 2; i < n + 1; i++)
        answer[i] = answer[i - 2] + answer[i - 1];

    cout << answer[n];
    return 0;
}