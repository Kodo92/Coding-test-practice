#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;

	vector<vector<int>> numbers;

	int startPos = 0, endPos = 0, subStartPos = 0, subEndPos = 0;

	for (int i = 1; i<s.size() - 1;)
	{
		startPos = s.find('{', i);
		endPos = s.find('}', i);
		string subString = s.substr(startPos + 1, endPos - startPos - 1);
		i = endPos + 1;

		vector<int> subNumbers;
		subStartPos = 0;
		while (true)
		{
			subEndPos = subString.find(',', subStartPos);
			subNumbers.push_back(stoi(subString.substr(subStartPos, subEndPos)));
			if (subEndPos == string::npos)
				break;
			subStartPos = subEndPos + 1;
		}
		numbers.push_back(subNumbers);
	}

	sort(numbers.begin(), numbers.end(), compare);

	bool findFlag = false;
	for (int i = 0; i<numbers.size(); i++)
	{
		for (int j = 0; j<numbers[i].size(); j++)
		{
			findFlag = false;
			for (int k = 0; k<answer.size(); k++)
			{
				if (numbers[i][j] == answer[k])
				{
					findFlag = true;
					break;
				}
			}
			if (!findFlag)
				answer.push_back(numbers[i][j]);
		}
	}

	return answer;
}


// 다른 사람 풀이 1
/*
	튜플의 부분 집합의 값인 정수가 등장한 횟수를 카운트 한다.
	제일 많이 등장한 횟수부터 순서대로 튜플의 순서이다.	
*/
/*
vector<int> solution(string s) {
	int st[101010] = {};
	vector<int> answer;
	string tmp;
	for (char i : s) {
		if (i - '0' >= 0 && i - '0' <= 9) {
			tmp += i;
		}
		else {
			if (tmp.length())
				st[stoi(tmp)]++, tmp.clear();
		}
	}
	vector<pair<int, int>> v;
	for (int i = 0; i <101010; i++)
		if (st[i])
			v.push_back({ st[i], i });
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto it : v) answer.push_back(it.second);
	return answer;
}
*/


void main()
{
	//solution("{{2},{2,12},{2,12,3},{2,12,3,4}}");
	solution("{{1,2,3},{2,1},{1,2,4,3},{2}");
}

/*
테스트 케이스 :
"{{1,2,3},{2,1},{1,2,4,3},{2}" == {2} , {2,1} , {1,2,3}, {1,2,4,3} == {2}, {2,1}, {2,1,3}, {2,1,4,3} 이다.
문제에서 원소의 순서가 다르면 서로 다른 튜플이라고 했지만, 하나의 튜플의 부분 집합들의 순서는 달라도 같은 튜플이다.
*/