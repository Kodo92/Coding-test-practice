#include<iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string inputData;
		cin >> inputData;
		set<char> Note;
		for (auto i : inputData)
		{
			auto retVal = Note.insert(i);
			if (retVal.second == false)
				Note.erase(retVal.first);
		}
		cout << '#' << test_case << ' ' << Note.size() << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}