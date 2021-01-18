#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Max process time : 82.93ms	&& Usage memory : 10.8MB
// Complexity : n log n
bool compare(const string _A, const string _B)
{
	return _A + _B > _B + _A;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> sortedStrings;
	for (auto i : numbers)
		sortedStrings.push_back(to_string(i));
	sort(sortedStrings.begin(), sortedStrings.end(), compare);

	if (*(sortedStrings.begin()) == "0")
		return "0";

	for (auto i : sortedStrings)
		answer += i;
	return answer;
}

void main()
{
	cout << solution({ 6,10,2 });
}