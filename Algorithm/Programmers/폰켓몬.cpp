#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	set<int> numbers;

	for (auto i : nums)
		numbers.insert(i);

	if (numbers.size() > nums.size() / 2)
		return nums.size() / 2;
	else
		return numbers.size();

}