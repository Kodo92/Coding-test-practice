#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dividedString(const string p, string *u, string *v)
{
	int count = 0, pos = 0;
	for (pos; pos<p.size(); pos++)
	{
		if (p[pos] == '(')
			count++;
		else
			count--;
		*u += p[pos];
		if (count == 0)
			break;
	}
	*v = p.substr(pos + 1);
}

bool checkCompleted(string u)
{
	for (int i = 0; i < u.size();)
	{
		if (u[i] == '(' && u[i + 1] == ')')
		{
			u.erase(i, 2);
			i = 0;
		}
		else
			i++;
	}
	if (u.size() > 0)
		return false;
	return true;
}

string newString(string u)
{
	string str(u);
	str.erase(0,1);
	str.pop_back();
	for (auto& i : str)
	{
		if (i == '(')
			i = ')';
		else
			i = '(';
	}
	str = '(' + str + ')';
	return str;
}

string trans(string p)
{
	if (p.size() == 0)
		return "";

	string u = "", v = "";

	dividedString(p, &u, &v);

	if (checkCompleted(u))
		return u + trans(v);
	else
		return newString(u) + trans(v);
}

string solution(string p) {
	string answer = "";

	if (checkCompleted(p))
		return p;

	answer = trans(p);

	return answer;
}

void main()
{
	//cout << solution("(()())()");
	//cout << solution(")(");
	cout << solution("()))((()");
}