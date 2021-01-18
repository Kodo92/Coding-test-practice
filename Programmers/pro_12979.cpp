/*
	[����] ������ ��ġ
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/12979
		��� : Summer/Winter Coding(~2018) Level 3
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int nowIndex = 0;
    int location = 1;       // station�� �ڿ���

    while (location <= n)
    {
        if (nowIndex < stations.size() && location >= stations[nowIndex] - w)
        {
            location = stations[nowIndex] + w + 1;
            nowIndex++;
        }
        else
        {
            location  += w * 2 + 1;
            answer++;
        }
    }


    return answer;
}

int main()
{
    cout<<solution(11, { 4,11 }, 1)<<endl;

    return 0;
}