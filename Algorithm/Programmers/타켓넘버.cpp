#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfsSum(vector<int> numbers, int target, int startIndex, int count)
{
	if (startIndex + count >= numbers.size())
		return 0;

	int answer = 0;
	int sum = 0;

	numbers[startIndex] *= -1;

	for (auto i : numbers)
		sum += i;
	if (sum == target)
		answer++;

	for (int i = startIndex + 1; i < numbers.size(); i++)
		answer += dfsSum(numbers, target, i, 0);

	return answer;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int sum = 0;

	for (auto i : numbers)
		sum += i;
	if (sum == target)
		answer++;

	for (int i = 0; i<numbers.size(); i++)
		answer += dfsSum(numbers, target, i, 0);

	return answer;
}

void main()
{
	cout << solution({ 1,1,1,1,1 }, 3);
}