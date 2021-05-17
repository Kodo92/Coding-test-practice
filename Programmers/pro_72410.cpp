/*
*	[프로그래머스] 신규 아이디 추천
*		출처 : https://programmers.co.kr/learn/courses/30/lessons/72410
*					2021 KAKAO BLIND RECRUITMENT
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkFullStop(string& str) {
    if (str.empty())
        return;

    if (str.front() == '.')
        str.erase(str.begin());
    if (str.back() == '.')
        str.pop_back();
}
string solution(string new_id) {
    
    for (int i = 0; i < new_id.size(); ) {
        new_id[i] = tolower(new_id[i]);
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || isdigit(new_id[i]))
            i++;
        else
            new_id.erase(new_id.begin()+i);
    }

    for (int i = 0; i < new_id.size()-1;) {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
            new_id.erase(new_id.begin() + i + 1);
        else
            i++;
    }
    checkFullStop(new_id);

    if (new_id.empty())
        new_id = 'a';

    if (new_id.size() > 15)
        new_id.erase(new_id.begin() + 15, new_id.end());

    checkFullStop(new_id);

    if (new_id.size() < 3) {
        for (int i = new_id.size(); i < 3; i++)
            new_id += new_id.back();
    }

    return new_id;
}

int main()
{
    solution("...!@BaT#*..y.abcdefghijklm");
}