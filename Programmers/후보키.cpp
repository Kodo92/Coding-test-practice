#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 유일성 체크
// parameter key를 비트연산을 이용해 몇번 column들의 조합인지 알아냅니다.
// column들의 값을 string에 합친다음 map을 이용해 중복확인을 합니다.
bool checkUnique(vector<vector<string>>& relation, int key)
{
	map<string, int> checker;
	vector<int> columnIndexs;

	for (int i = 0; i < relation.front().size(); i++)
	{
		// relation.front().size()가 4일 경우 index들은 : 0001, 0010, 0100, 1000이 됩니다.
		int index = 1 << i;

		// key가 1이고 index가 1이면 and 결과는 0
		// key가 6 (0110)이면 index가 2 (0010), 4 (0100) 일때 유효합니다. 
		// 그래서 2, 4 인 경우 column들의 집합임은 {1,2}임을 알 수 있습니다.
		if ((key & index) == 0)
			continue;
		columnIndexs.push_back(i);
	}

	// relation들의 값이 string이므로, map<string,int>를 이용해 중복체크를 해줍니다.
	for (auto& value : relation)
	{
		string str = "";
		// 1,2번 column들의 집합이라면 1,2,3번 column의 값들을 더해줍니다.
		// 100 / ryan / music / 2 => string str = "ryanmusic"
		for (auto i : columnIndexs)
			str += value[i];

		if (!checker[str])
			checker[str] = 1;
		else
			return false;
	}
	return true;
}

bool checkMinimality(vector<int>& candidates, int key)
{
	// 기존 후보키의 값이 파라메터로 들어온 key에 속하는지 확인합니다.
	// key : 11, candidates value : 6 이라면 key는 1110, value : 0110입니다. 
	// key & value = 6 이 나와 11은 부분집합으로 6을 갖음을 알 수 있습니다.
	for (auto value : candidates)
	{
		if ((key & value) == value)
			return false;
	}
	return true;
}

int solution(vector<vector<string>> relation) {

	vector<int> answer;

	for (int i = 1; i< (1 << relation.front().size()); i++)
	{
		if (checkUnique(relation, i) && checkMinimality(answer, i))
			answer.push_back(i);
	}

	return answer.size();
}

/*
비트 연산을 이용한 조합 경우의 수 계산.
and 연산을 이용한 중복 확인
*/