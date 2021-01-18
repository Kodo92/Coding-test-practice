#include<iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// sort 대신 map을 사용한 케이스 : 최대 0.51ms, 4.18MB
/*
vector<string> solution(vector<string> files) {
	vector<string> answer;
	
//			Head			Number, Index
	map<string, map<int, vector<int>>> fileList;

	for (int i = 0; i < files.size(); i++)
	{
		bool headFlag = true;
		string head = "";
		string number = "";
		size_t numberSourcePos = 0;
		for (int j = 0; j < files[i].size(); j++)
		{
			if (headFlag)
			{
				if (isdigit(files[i][j]) != 0)
				{
					headFlag = false;
					head = files[i].substr(0, j);
					transform(head.begin(), head.end(), head.begin(), ::toupper);
					numberSourcePos = j;
				}
			}
			if(!headFlag)
			{
				if (isdigit(files[i][j]) != 0 && number.size() < 5)
					number += files[i][j];
				else
					break;
			}
		}
		fileList[head][stoi(number)].push_back(i);
	}

	for (const auto& value : fileList)
	{
		for (const auto& inMapValue : value.second)
		{
			for (const auto index : inMapValue.second)
				answer.push_back(files[index]);
		}
	}
	return answer;
}
*/

// std::stable_sort 사용한 케이스 : 최대 1.04ms, 4.27MB
// 참고 블로그 : https://dev-dream-world.tistory.com/73
struct File {
	string head;
	string number;

	File(const string& name) 
	{
		int pos = 0;
		for (; pos < name.size(); pos++)
		{
			if (isdigit(name[pos]) == 0)
				head += name[pos];
			else
				break;
		}

		transform(head.begin(), head.end(), head.begin(), toupper);
		
		for (; pos < name.size(); pos++)
		{
			if (isdigit(name[pos]) != 0 && number.size() < 5)
				number += name[pos];
			else
				break;
		}
	}
};

const bool compare(const pair<int,File>& a, const pair<int, File>& b)
{
	if (a.second.head == b.second.head)
		return stoi(a.second.number) < stoi(b.second.number);
	else
		return a.second.head < b.second.head;
}

vector<string> solution(vector<string> files)
{
	vector<pair<int,File>> fileList;
	for (int pos = 0 ; pos < files.size();pos++)
		fileList.push_back(make_pair(pos,File(files[pos])));

	stable_sort(fileList.begin(), fileList.end(), compare);

	vector<string> answer;
	for (const auto& value : fileList)
		answer.push_back(files[value.first]);
	return answer;
}

/*
주의]
Number는 최대 5글자이다.

TEST_CASE
{F-15}
 {foo010bar020.zip}
*/