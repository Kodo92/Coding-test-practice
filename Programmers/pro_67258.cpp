/*
	[PRO] 보석 쇼핑
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67258

	[풀이 방법] : 투 포인터 / 슬라이딩 윈도우
		1. 보석이 몇종류 있는지 확인한다.
			- set/map을 이용
		2. 배열을 순회하면서 endIndex 위치의 보석을 map (nowStatus)에 넣는다. 두번째 인자는 endIndex다.
			- 이미 들어있는 보석이 다시 나올경우 인덱스를 갱신해준다.
		3. nowStatus의 크기가 보석의 종류 갯수와 같다면 모든 보석을 구매했다는 것 이다.
			- nowStatus에는 각 보석의 인덱스가 있다. 최소 인덱스 값과 최대 인덱스 값을 구한다.
			- 위에서 구한 두개의 값을 이용해 구간의 길이를 찾는다.
		4. 구간의 길이와 시작, 끝 인덱스를 구했다면 map (answer)에 insert해준다.
			- 최소 구간의 길이를 얻기 위해서이며, answer의 value도 map인 이유는 길이가 같을 때 시작 인덱스가 작은 값을 찾기 위해서다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void isAll(const map<string, int>& lists, int* start, int * end)
{
	for (const auto& i : lists)
	{
		*start = std::min(*start, i.second);
		*end = std::max(*end, i.second);
	}
}
vector<int> solution(vector<string> gems) {
	map<string, int> gemLists;

	for (const auto& i : gems)
	{
		if (gemLists.find(i) == gemLists.end())
			gemLists[i];
	}

	map<string, int> nowStatus;
	map<int, map<int, int>> answer;
	int endIndex = 0;
	while (true)
	{
		if (endIndex >= gems.size())
			break;
		nowStatus[gems[endIndex++]] = endIndex;		
		int start=gems.size(), end = 0;
		if (gemLists.size() == nowStatus.size())
		{
			isAll(nowStatus, &start, &end);
			answer[(end - start + 1)].insert({ start + 1, end + 1 });
		}
	}

	return{ answer.begin()->second.begin()->first,answer.begin()->second.begin()->second };
}

int main()
{
	solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	return 0;
}