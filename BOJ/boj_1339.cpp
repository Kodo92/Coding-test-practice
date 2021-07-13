#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <string>

int main() {

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N = 0;
	std::cin >> N;

	std::vector<std::string> words(N);
	std::vector<int> lengths(N);
	while (N--) {
		std::cin >> words[N];
		lengths[N] = words[N].size();
	}

	struct  {
		bool operator() (std::string& a, std::string& b) const { return a.size() > b.size(); }
	} stringLess;

	std::sort(words.begin(), words.end(), stringLess);
	int maxCount = words.front().size();
	for (std::string& str : words) {
		if (str.size() != maxCount) {
			int dest = maxCount - str.size();
			for (int i = 0; i < dest; i++)
				str = '0' + str;
		}
	}

	std::map<char, char> alpabets;
	char number = '9';
	while (true)
	{
		bool isEnd = true;
		int index = 0;
		for (index = 0; index < maxCount; index++) {
			if (isdigit(words.front()[index]) == 0) {
				isEnd = false;
				break;
			}
		}

		if (isEnd)
			break;

		for (int i = 0; i < words.size(); i++) {
			if (words[i][index] == '0') break;

			if (alpabets.count(words[i][index]) == 0) {
				alpabets[words[i][index]] = number;
				words[i][index] = number--;
			}
			else {
				words[i][index] = alpabets[words[i][index]];
			}
		}
	}

	int answer = 0;
	for (std::string i : words)
		answer += std::stoi(i);

	std::cout << answer;
	return 0;
}

/*
10
ABB
BB
BB
BB
BB
BB
BB
BB
BB
BB
*/