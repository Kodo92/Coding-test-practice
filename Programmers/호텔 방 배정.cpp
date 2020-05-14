#include <iostream>
#include <vector>

#include <map>

using namespace std;

map<long long, long long> m;

long long find(long long u)
{
	if (!m[u]) return u;
	return m[u] = find(m[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (auto& i : room_number)
	{
		if (!m[i])
		{
			answer.push_back(i);
			m[i] = find(i + 1);
		}
		else
		{
			long long temp = find(i);
			answer.push_back(temp);
			m[temp] = find(temp + 1);
		}
	}
	return answer;
}

void main()
{
	solution(10, { 1,3,4,1,3,1 });
}