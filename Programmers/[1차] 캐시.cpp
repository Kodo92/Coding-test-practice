#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<string>::iterator find(deque<string>& cache, string& s)
{
	for (int i = 0; i<cache.size(); i++)
	{
		if (cache[i] == s)
			return cache.begin() + i;
	}
	return cache.end();
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	if (cacheSize == 0)
		return cities.size() * 5;

	for (auto& i : cities)
		transform(i.begin(), i.end(), i.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });

	deque<string> cache;

	for (auto& i : cities)
	{
		deque<string>::iterator retval = find(cache, i);
		if (retval == cache.end())
		{
			if (cache.size() >= cacheSize)
				cache.pop_front();
			answer += 5;
		}
		else
		{
			cache.erase(retval);
			answer += 1;
		}
		cache.push_back(i);
	}
	return answer;
}

// cacheSize == 0 일 때 pop 하면 crash.