#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	map<string, int> A;
	string newString = "";
	float interCount = 0, i = 0;

	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	pair<map<string, int>::iterator, bool> retVal;
	for (i = 0; i<str1.size(); i++)
	{
		newString = str1.substr(i, 2);
		if (newString[0] > 'Z' || newString[0] < 'A'
			|| newString[1] > 'Z' || newString[1] < 'A')
			continue;
		retVal = A.insert(make_pair(newString, 0));
		if (retVal.second == false)
			interCount--;
	}


	for (i = 0; i<str2.size(); i++)
	{
		newString = str2.substr(i, 2);
		if (newString[0] > 'Z' || newString[0] < 'A'
			|| newString[1] > 'Z' || newString[1] < 'A')
			continue;
		retVal = A.insert(make_pair(newString, 0));
		if (retVal.second == false)
			interCount++;
	}
	if (A.size() == 0)
		return 65536;

	float cal = (interCount) / static_cast<float>((A.size()));
	answer = cal * 65536;
	return answer;
}

int main()
{
	cout << solution("aa1+aa2", "AAAA12");

	return 0;
}