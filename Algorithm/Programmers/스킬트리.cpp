#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<bool> satisfyConditions;

	satisfyConditions.resize(skill.size());

	int retVal = string::npos;
	for (auto& i : skill_trees)
	{
		answer++;
		satisfyConditions.clear();
		satisfyConditions.resize(skill.size());
		for (int j = 0; j<i.size(); j++)
		{
			retVal = skill.find(i[j]);
			if (retVal == string::npos)
				continue;
			if (retVal > 0)
			{
				if (satisfyConditions[retVal - 1] == false)
				{
					answer--;
					break;
				}
				else
					satisfyConditions[retVal] = true;
			}
			else
				satisfyConditions[retVal] = true;
		}
	}
	return answer;
}

void main()
{
	cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
}