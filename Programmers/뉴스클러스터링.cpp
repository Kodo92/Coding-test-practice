#include <string>
#include <algorithm>
#include <set>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
	transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });

	multiset<string> sum_of_sets;
	float intersection = 0, sumset = 0;

	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
		{
			sum_of_sets.insert(str1.substr(i, 2));
			sumset++;
		}
	}

	for (int i = 0; i<str2.size() - 1; i++)
	{
		if (str2[i] < 'A' || str2[i] > 'Z' || str2[i + 1] < 'A' || str2[i + 1] > 'Z')
			continue;
		string newString = str2.substr(i, 2);
		auto retVal = sum_of_sets.find(newString);
		if (sum_of_sets.end() == retVal)
			sumset++;
		else
		{
			sum_of_sets.erase(retVal);
			intersection++;
		}
	}

	float a = (intersection / sumset) * 65536;
	return a;
}

/*
int main()
{
//	cout << solution("aa1+aa2", "AAAA12");
//	cout << solution("handshake", "shake hands");
	cout << solution("E=M*C^2", "e=m*c^2");
	return 0;
}
*/