#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string m, vector<string> musicinfos) {
	map<int, vector<string>> answer;

	for (auto& value : musicinfos)
	{
		// ���� ����� �ð��� ���� ���մϴ�.	
		// ���ڿ� value���� �ð��� ��ġ�� �����Դϴ�.
		int startHour = stoi(value);
		int startMin = stoi(&value[3]);
		int endHour = stoi(&value[6]);
		int endMin = stoi(&value[9]);

		// �ִ� ����ð��� 00:00 ~ 23:59 ���� ����� ����Ÿ���� ����մϴ�.
		int runningTime = (endMin - startMin) + ((endHour - startHour) * 60);

		// ���ڿ� value���� �̸��� 1~64���� ������ ���� ���� ����ؼ� �̸��� ã���ݴϴ�.
		size_t pos = value.find(',', 12);
		string name = value.substr(12, (pos - 12));
		pos += 1;		// pos + 1�� �������ν� �Ǻ��� ���������� pos�� �̵���ŵ�ϴ�.

		int melodySize = value.size() - pos;

		// �Ǻ��� ���� �и��մϴ�.
		// C#, F# ���� ��� �ܼ� ���ڿ� ++�� �ϰԵǸ� #�� 1������ ó���ϴ� ������ �߻��Ͽ� �Ʒ��� ���� ����� ����߽��ϴ�.
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

		// melody�� m�� ���մϴ�.
		// ��� : ABC, �Ǻ� : ABC#ABC#ABC�� ��� ABC#������ FAIL�� �� �� �ֱ⿡ �ݺ����� �����ݴϴ�.
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
C�� C#����

1.
melody�� ��� �ð���ŭ ++ �� �� #�� 1������ ó���Ǵ� ���� ����.
{
	int melodySize = value.size() - pos;
	for (int i = 0; i<runningTime; i++)
		melody += value[pos + (i % melodySize)];
}
 => �ذ� ��� VECTOR�� 1���� ������ �ְ� ���ڿ��� ġȯ�Ѵ�.

 2.
 �Ǻ� : ABC#ABC#ABC �̰� ��� ABC�� �� FAILó����.
 [4]�� #�̶� FAIL ó����Ų�� ����.
 {
	pos = melody.find(m);
	if (pos == melody.npos)
		continue;
	pos = (pos + m.size()) % melody.size();
	if (melody[pos] == '#')
		continue;
 }

*/