#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const vector<int> a, const vector<int> b)
{
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] > b[1];
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	map<pair<int, int>, int> values;

	for (int i = 0; i < nodeinfo.size(); i++)
		values[make_pair(nodeinfo[i][0], nodeinfo[i][1])] = i+1;

	sort(nodeinfo.begin(), nodeinfo.end(), compare);

	return answer;
}

void main()
{
	solution({ {5,3},{11,5},{13,3},{3,5 },{6,1},{1,3},{8,6},{7,2},{2,2} });
}