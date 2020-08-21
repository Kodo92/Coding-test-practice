/*
	[����] ���ڿ� ����
		���� ��ó : https://www.acmicpc.net/problem/9935

	[���� ����]
		1. ���ڿ� ��ȸ�ϸ鼭 ���� ���ڿ� �����ϸ� ���� �� ���� ���ڿ��� �������� ���� �� ���� ����. -> �ð��ʰ�
		2. ������ �̿��� input�� �����ϰ� ������ ���� ���� ���ڿ� ��, �ӽ� ���ÿ� ��ġ�� ���� ���� ���ڿ� üũ -> �ð� �ʰ� 

	[����]
		https://jaimemin.tistory.com/823
*/

#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string input, boomString;
	std::cin >> input >> boomString;

	std::string st;
	for (int i = 0; i < input.size(); i++)
	{
		st.push_back(input[i]);
		if (st.size() >= boomString.size() && st.back() == boomString.back())
		{
			bool isDetection = true;
			int k = 0, stSize = st.size()-1;
			for (auto j = boomString.rbegin(); j != boomString.rend(); j++, k++)
			{
				if (st[stSize - k] != *j)
				{
					isDetection = false;
					break;
				}
			}
			if (isDetection)
			{
				for (int j = 0; j < boomString.size(); j++)
					st.pop_back();
			}
		}
	}

	if (st.size() == 0)
		std::cout << "FRULA";
	else
		std::cout << st;

	return 0;
}