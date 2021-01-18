#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> dic{ {"A",1},{"B",2},{"C",3},{"D",4},{"E",5},{"F",6},{"G",7},{"H",8},{"I",9},{"J",10},{"K",11},{"L",12},{"M",13},{"N",14},{"O",15},{"P",16},{"Q",17},{"R",18},{"S",19},{"T",20},{"U",21},{"V",22},
	{"W",23},{"X",24},{"Y",25},{"Z",26} };

	for (int i = 0; i < msg.size(); )
	{
		string str = "";
		// 연속된 문자열 중에서 사전에 등록된 최대의 문자열 탐색
		while (true)
		{
			if (i >= msg.size())
				break;

			str += msg[i];

			if (dic[str] == 0)
			{
				dic[str] = dic.size();
				str.pop_back();

				break;
			}
			i++;
		}
		answer.push_back(dic[str]);
	}
	return answer;
}