/*
*	[����] �޴� ������
*		��ó : https://programmers.co.kr/learn/courses/30/lessons/72411
*		��� : 2021 KAKAO BLIND RECRUITMENT
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
*   [�ٽ�]
*       orders�� ���ڿ����� course���� ������ŭ ���� ���� �� count
*       orders���� ���ĵ��� �ʾҴ�. -> �������� ������� ���ڿ��� ������ ������� ����.
*       new_str.empty() / counts.empty() ���
* 
*   [���� ���]
*       2021.05.21. - Slove
*       2021.05.21. - �������� ���� ���ڿ� ���� -> orders ���� �� �������� ���� (�ӵ� ���� ���)
*/