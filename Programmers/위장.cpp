#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> clothesMap;

	for (auto i : clothes)
			clothesMap[i[1]]++;

	for (auto i : clothesMap)
		answer *= (i.second + 1);
	return answer-1;
}

void main()
{

}