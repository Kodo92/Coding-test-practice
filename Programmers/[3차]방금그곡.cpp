#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string m, vector<string> musicinfos) {
	map<int, vector<string>> answer;

	for (auto& value : musicinfos)
	{
		// 음악 재생의 시간과 분을 구합니다.	
		// 문자열 value에서 시간의 위치는 고정입니다.
		int startHour = stoi(value);
		int startMin = stoi(&value[3]);
		int endHour = stoi(&value[6]);
		int endMin = stoi(&value[9]);

		// 최대 재생시간은 00:00 ~ 23:59 임을 고려해 러닝타임을 계산합니다.
		int runningTime = (endMin - startMin) + ((endHour - startHour) * 60);

		// 문자열 value에서 이름은 1~64자의 범위를 갖는 점을 고려해서 이름을 찾아줍니다.
		size_t pos = value.find(',', 12);
		string name = value.substr(12, (pos - 12));
		pos += 1;		// pos + 1을 해줌으로써 악보의 시작점으로 pos를 이동시킵니다.

		int melodySize = value.size() - pos;

		// 악보의 음을 분리합니다.
		// C#, F# 같은 경우 단순 문자열 ++로 하게되면 #도 1음으로 처리하는 문제가 발생하여 아래와 같은 방법을 사용했습니다.
		vector<string> melodyWords;
		for (int i = pos; i <value.size(); i++)
		{
			string str = "";
			str += value[i];
			if (i + 1 < value.size() && value[i + 1] == '#')
			{
				str += value[i + 1];
				i++;
			}
			melodyWords.push_back(str);
		}

		string melody = "";

		for (int i = 0; i<runningTime; i++)
			melody += melodyWords[i%melodyWords.size()];

		// melody와 m을 비교합니다.
		// 듣기 : ABC, 악보 : ABC#ABC#ABC의 경우 ABC#때문에 FAIL이 뜰 수 있기에 반복문을 돌려줍니다.
		pos = 0;
		while (true)
		{
			pos = melody.find(m,pos);
			if (pos == melody.npos)
				break;
			pos = (pos + m.size()) % melody.size();
			if (melody[pos] == '#')
				continue;
			answer[runningTime].push_back(name);
			break;
		}
	}

	if (answer.size() == 0)
		return "(None)";

	return answer.rbegin()->second.front();
}

void main()
{
	cout <<solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:14,WORLD,ABCDEF", "13:00,13:05,WORLD,ABCDEF"}) << endl;
	cout <<solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" }) << endl;
	cout << solution("ABC", { "13:00,13:09,RLD,ABC#ABC#ABC" }) << endl;
}

/*
C와 C#구분

1.
melody를 경과 시간만큼 ++ 할 때 #도 1분으로 처리되는 문제 있음.
{
	int melodySize = value.size() - pos;
	for (int i = 0; i<runningTime; i++)
		melody += value[pos + (i % melodySize)];
}
 => 해결 방안 VECTOR에 1글자 단위로 넣고 문자열로 치환한다.

 2.
 악보 : ABC#ABC#ABC 이고 듣기 ABC일 때 FAIL처리됨.
 [4]가 #이라서 FAIL 처리시킨게 원인.
 {
	pos = melody.find(m);
	if (pos == melody.npos)
		continue;
	pos = (pos + m.size()) % melody.size();
	if (melody[pos] == '#')
		continue;
 }

*/