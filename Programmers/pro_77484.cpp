#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int getRank(const int count) {
    switch (count)
    {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    set<int> nums;
    for (int i : win_nums)
        nums.insert(i);

    int collectCount = 0;
    int zeroCount = 0;
    for (int i : lottos) {
        if (i == 0)
            zeroCount++;
        else {
            if (nums.count(i) != 0) {
                collectCount++;
                nums.erase(i);
            }
        }
    }

    int high = collectCount + min(zeroCount,(int)nums.size());
    int low = collectCount;

    
    return { getRank(high),getRank(low) };
}

int main()
{
    solution({ 44,1,0,0,31,25 }, { 31,10,45,1,6,19 });
    solution({ 44,1,0,0,31,25 }, { 31,10,45,1,6,19 });
}