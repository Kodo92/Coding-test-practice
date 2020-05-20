#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());

	int average = M / budgets.size();

	if (budgets.front() >= M)
		return average;

	int sum = 0;
	for (int i = 0; i<budgets.size(); i++)
	{
		if (average < budgets[i])
			return average;

		sum += budgets[i];
		if (i + 1 == budgets.size() && sum <= M)
			return budgets.back();

		average = (M - sum) / (budgets.size() - (i + 1));

	}

	if (average > sum)
		return budgets.back();
}

/*
1. 예산요청 값들을 오름차순 정렬
2. 총 예산의 평균을 구함.
3. 반복문을 돌면서 예산요청값의 합과, 합을 제외한 나머지 예산 값들의 평균을 구함.
4. 평균값이 예산요청 값보다 크면 최대 값.
5. 배열의 마지막 위치의 경우는 예산 요청값들보다 평균이 컸다. -> 예산 요청대로 값을 다 줄 수 있다.
*/