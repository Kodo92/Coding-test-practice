#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	bool space = true;
	for (auto& i : s)
	{
		if (i == ' ')
			space = true;
		else if (space)
		{
			i = toupper(i);
			space = false;
		}
		else
			i = tolower(i);
	}
	return s;
}