#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

long long solution(string expression) {
	long long answer = 0;

	deque<long long> numbers;
	deque<long long> result;
	vector<int> operat{ -3,-2 ,-1 };
	int startPos = 0, endPos = 0;

	for (int i = endPos; i < expression.size(); i++)
	{
		if (expression[i] < '0' || expression[i] > '9')
		{
			numbers.push_back(stoll(&expression[startPos]));
			startPos = i + 1;

			if (expression[i] == '+')
				numbers.push_back(-1);
			else if (expression[i] == '-')
				numbers.push_back(-2);
			else
				numbers.push_back(-3);
		}
	}
	if (startPos < expression.size())
		numbers.push_back(stoll(&expression[startPos]));

	long long value = 0;
	do
	{
		deque<long long> temp(numbers);
		for (auto i : operat)
		{
			value = 0;
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[j] == i)
				{
					switch (i)
					{
					case -1:
						value = temp[j - 1] + temp[j + 1];
						break;
					case -2:
						value = temp[j - 1] - temp[j + 1];
						break;
					case -3:
						value = temp[j - 1] * temp[j + 1];
						break;
					default:
						break;
					}

					temp[j - 1] = value;
					temp.erase(temp.begin() + j, temp.begin() + (j + 2));
					j = j - 1;
				}
			}

		}
		result.push_back(abs(temp.front()));
	} while (next_permutation(operat.begin(), operat.end()));
	sort(result.begin(), result.end());
	answer = result.back();
	return answer;
}