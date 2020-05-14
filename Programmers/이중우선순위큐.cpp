#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer(2);

	deque<int> queue;

	for (auto i : operations)
	{
		if (i[0] == 'I')
		{
			queue.push_back(atoi(&i[2]));
			sort(queue.begin(), queue.end());
		}
		else
		{
			if (queue.empty()) continue;
			if (i[2] == '1')
				queue.pop_back();
			else
				queue.pop_front();
		}
	}

	if (queue.empty())
		return answer;

	answer[0] = queue.back();
	answer[1] = queue.front();
	return answer;
}

void main()
{
	solution({ });
}