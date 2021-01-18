#include <iostream>
#include <stack>
#include <string>

int main() 
{
	int cnt = 1;
	while (true)
	{
		std::string str;
		int answer = 0;

		std::stack<char> st;
		std::cin >> str;

		if (str[0] == '-')
			break;

		for (auto& i : str)
		{
			if (st.empty() && i == '}')
			{
				answer++;
				i = '{';
				st.push(i);
			}
			else if (!st.empty() && i == '}')
				st.pop();
			else
				st.push(i);
		}
		answer += st.size() / 2;	// 끝이 {{ 인 경우
		std::cout << cnt << ". " << answer << std::endl;
		cnt++;
	}

	return 0;
}