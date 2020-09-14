/*
	[프로] 외벽 점검
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/60062
		비고 : 2020 KAKAO BLIND RECRUITMENT
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<bool,int> isRepair(const vector<int>& weak, const vector<int>& dist, const int weakSize, const int permutation)
{
	vector<int> friendIndex;
	for (int i = 0; i < dist.size(); i++)
	{
		if (permutation & (1 << i))
			friendIndex.push_back(i);
	}

	do {
		for (int i = 0; i < weakSize; i++)
		{
			int endPosition = weak[i] + dist[friendIndex.front()];
			int index = 0;
			bool isSuccess = true;
			for (int j = i; j < (i + weakSize); j++)
			{
				if (weak[j] > endPosition)
				{
					index++;
					if (index >= friendIndex.size())
					{
						isSuccess = false;
						break;
					}
					endPosition = weak[j] + dist[friendIndex[index]];
				}
			}
			if (isSuccess)
				return { isSuccess,friendIndex.size() };
		}
	} while (next_permutation(friendIndex.begin(), friendIndex.end()));
	return { false,-1 };
}

int solution(int n, vector<int> weak, vector<int> dist) {

	int weakSize = weak.size();
	weak.resize(weakSize*2);
	for (int i = 0; i < weakSize; i++)
		weak[i + weakSize] = weak[i] + n;

	int maximum = 0;
	for (int i = 0; i < dist.size(); i++)
		maximum = maximum | (1 << i);

	if (!isRepair(weak, dist, weakSize, maximum).first)
		return -1;

	int answer = dist.size();
	for (int i = 1; i < maximum; i++)
	{
		auto retval = isRepair(weak, dist, weakSize,i );
		if (!retval.first || retval.second >= answer)
			continue;
		answer = retval.second;
	}
	return answer;
}

int main()
{
	//cout << solution(12, { 1,5,6,10 }, { 1,2,3,4 }) << endl;
	//cout << solution(12, { 1,3,4,9,10 }, { 3,5,7}) << endl;
	//cout << solution(200, { 0,100 }, { 1,1 }) << endl;
	//cout << solution(50, { 1,6,40 }, { 1,5 }) << endl;
	cout << solution(200, { 0,10,50,80,120,160 }, { 1,10,5,40,30}) << endl;


	return 0;
}