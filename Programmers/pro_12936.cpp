/*
	[프로] 줄 서는 방법
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12936
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    int divided = factorial(n) / n;
    int index = k / divided;
    int count = (k - 1) % divided;
    vector<int> answer(n);
    answer[0] = index + 1;
    int value = 1;
    for (int i = 1; i < n; i++,value++)
    {
        if (value == (index + 1))
            value++;

        answer[i] = value;
    }

    do {
        if (count == 0)
            return answer;
        count--;
    } while (next_permutation(answer.begin(), answer.end()));
}

int main()
{
    solution(3, 5);
	return 0;
}