/*
	[프로] 순위
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/49191
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {

	vector<vector<bool>> floyd(n, vector<bool>(n, false));
	for (const auto& i : results)
		floyd[i[0]-1][i[1]-1] = true;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (floyd[j][i] && floyd[i][k])
					floyd[j][k] = true;
			}
		}
	}
	int answer = 0;
	for (size_t i = 0; i < n; i++) {
		int count = 0;
		for (size_t j = 0; j < n; j++) {
			if (floyd[i][j] || floyd[j][i]) count++;
		}
		if (count == n - 1) answer++;
	}
	return answer;
}

int main()
{
	cout << solution(5,{ {4,3},{4,2},{3,2},{2,5},{1,2} }) << endl;

	return 0;
}