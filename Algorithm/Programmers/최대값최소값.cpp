#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	deque<int> numbers;
	int retVal = 0, pos = 0;
	while (true)
	{
		retVal = s.find(' ', pos);
		numbers.push_back(stoi(s.substr(pos, (retVal - pos))));
		if (retVal == string::npos)
			break;
		pos = retVal + 1;
	}
	sort(numbers.begin(), numbers.end());
	answer += to_string(numbers.front());
	answer += ' ';
	answer += to_string(numbers.back());
	return answer;
}

void main()
{
	solution("-1 -2 3 4");
}