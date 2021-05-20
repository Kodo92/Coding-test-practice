/*
*	[프로] 메뉴 리뉴얼
*		출처 : https://programmers.co.kr/learn/courses/30/lessons/72411
*		비고 : 2021 KAKAO BLIND RECRUITMENT
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i : course) {
        map<string, int> counts;
        for (string str : orders) {
            
            vector<int> temp(str.size(),0);
            for (int j = str.size() - i; j < str.size(); j++)
                temp[j] = 1;
            do {
                string new_str;
                for (int k = 0; k < str.size(); k++) {
                    if (temp[k] == 1)
                        new_str += str[k];
                }
                if (!new_str.empty()) {
                    sort(new_str.begin(), new_str.end());
                    counts[new_str]++;
                }
            } while (next_permutation(temp.begin(), temp.end()));
        }
        map<int, vector<string>> result;
        for (auto& j : counts) {
            if(j.second >= 2)
                result[j.second].push_back(j.first);
        }

        if (result.empty())
            continue;

        for (auto& j : result.rbegin()->second) {
            answer.push_back(j);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    //solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    solution({ "XYZ", "XWY", "WXA" }, { 2,3,4 });

    return 0;
}

/*
*   [핵심]
*       orders의 문자열들의 course들의 갯수만큼 조합 실행 후 count
*       orders들은 정렬되지 않았다. -> 조합으로 만들어진 문자열의 순서가 보장되지 않음.
*       new_str.empty() / counts.empty() 고려
* 
*   [수정 기록]
*       2021.05.21. - Slove
*       2021.05.21. - 조합으로 만든 문자열 정렬 -> orders 정렬 후 시작으로 변경 (속도 조금 향상)
*/