/*
	[프로] 멀리 뛰기
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12914
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	long long answer = 0;
	vector<long long> fibonach(n);
	fibonach[0] = 1;
	fibonach[1] = 2;
	for (int i = 2; i < n; i++)
		fibonach[i] = fibonach[i - 2] + fibonach[i - 1];
	return fibonach[n-1]%1234567;
}

int main()
{


	return 0;
}