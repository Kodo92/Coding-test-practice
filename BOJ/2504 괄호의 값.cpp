#include <iostream>
#include <string>
#include <vector>

const char getDestChar(const char ch)
{
	switch (ch)
	{
	case '(':
		return ')';
	case '[':
		return']';
	default:
		return '-';
	}
}

int getValue(const char ch)
{
	switch (ch)
	{
	case '(':
		return 2;
	case '[':
		return 3;
	default:
		return 0;
	}
}

int cal(std::string& str )
{
	std::vector<int> values;
	while (true)
	{
		int value = 0, startIndex = 0;
		char destChar = getDestChar(str[0]);
		if (destChar == '-')
			break;
		bool isFind = false;
		for (int i = 1; i < str.size(); i++)
		{
			if (destChar != str[i])
			{
				if (str[i] == '[' || str[i] == '(')
				{
					startIndex = i;
					value = 0;
					destChar = getDestChar(str[i]);
				}
				else if (str[i] != ')' && str[i] != ']')
					value += values[str[i]];
				else
					return 0;
			}
			else
			{
				int tempValue = getValue(str[startIndex]);
				if (value != 0) tempValue = value * tempValue;
				values.push_back(tempValue);
				str[startIndex] = values.size()-1;
				str.erase(startIndex + 1, (i - startIndex));
				isFind = true;
				break;
			}
		}
		if (!isFind)
			return 0;
	}
	
	return (values.size() > 0) ? values.back() : 0;
}

int main()
{
	std::string str;
	std::cin >> str;

	int answer = 0;

	while (str.size() != 0)
	{
		int retval = cal(str);
		if (retval == 0)
		{
			answer = 0;
			break;
		}
		answer += retval;
		str.erase(str.begin());
	}

	std::cout << answer;
	return 0;
}

/*
testcase
(()[[]])([]) : 28
([)] : 0
(([)]) : 0
(()[[]])(([)]) : 0
(((((((((((((())))))))))))))
*/