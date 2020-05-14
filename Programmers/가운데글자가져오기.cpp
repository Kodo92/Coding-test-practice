#include <iostream>
#include <string>
#include <vector>

using namespace std;

// max] 0.02ms / 3.91mb
string solution(string s) {
	string answer = "";
	int stringSize = s.length();
	int Quotient = 0, Remainder = 0;
	Quotient = (stringSize / 2) - 1;
	Remainder = stringSize % 2;

	if (Remainder == 1)
		answer += s.at(Quotient);
	else
	{
		answer = string(1,s.at(Quotient)) + string(1,s.at(Quotient + 1));
	}
	return answer;
}

// Others : 다른사람 코드
// s.length() & 1 : 비트연산
// max] 0.01ms / 3.93mb
/*
string solution(string s) {
	return s.length() & 1 ? s.substr(s.length()*0.5, 1) : s.substr(s.length()*0.5 - 1, 2);
}
*/

int main()
{
	string a = "qer";
	auto val = a.length() & 1;
	cout<<solution("qwer");
	return 0;
}