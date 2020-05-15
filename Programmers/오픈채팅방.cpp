#include <string>
#include <vector>
#include <map>

using namespace std;

void getData(string s, string& command, string& uid, string& name)
{
	size_t sourcePos = 0;
	size_t destPos = s.find(' ', sourcePos);

	command = s.substr(sourcePos, (destPos - sourcePos));
	sourcePos = destPos + 1;

	destPos = s.find(' ', sourcePos);
	uid = s.substr(sourcePos, (destPos - sourcePos));
	sourcePos = destPos + 1;

	destPos = s.find(' ', sourcePos);
	name = s.substr(sourcePos, (destPos - sourcePos));
	sourcePos = destPos + 1;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<int, string>> sequence;
	map<string, string> userData;

	for (auto& i : record)
	{
		string command, uid, name;
		getData(i, command, uid, name);

		if (command == "Enter")
		{
			sequence.push_back(make_pair(1, uid));
			userData[uid] = name;
		}
		else if (command == "Leave")
			sequence.push_back(make_pair(2, uid));
		else
			userData[uid] = name;
	}

	for (auto& i : sequence)
	{
		switch (i.first)
		{
		case 1:
		{
			string str = userData[i.second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(str);
			break;
		}
		case 2:
		{
			string str = userData[i.second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(str);
			break;
		}
		default:
			break;
		}
	}

	return answer;
}