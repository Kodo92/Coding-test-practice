/*
	[프로] 숫자 게임
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12987
		비고 : Summer/Winter Coding(~2018)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	sort(B.begin(), B.end());
	vector<bool> isUsed(B.size(), false);

	int answer = 0;
	for (const auto i : A)
	{
		auto upper = upper_bound(B.begin(), B.end(), i);
		if (upper == B.end())
			continue;
		for (upper; upper != B.end(); upper++)
		{
			int index = distance(B.begin(), upper);
			if (!isUsed[index])
			{
				answer++;
				isUsed[index] = true;
				break;
			}
		}
	}
	return answer;
}
int main()
{
	cout << solution({5,1,3,7}, {2,2,6,8}) << endl;
	cout << solution({ 2,2,2,2 }, { 1,1,1,1 }) << endl;
}