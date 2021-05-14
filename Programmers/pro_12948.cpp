#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int count = phone_number.size() - 4;
    string star = "";
    for (int i = 0; i < count; i++)
        star += '*';
    phone_number.replace(0, count, star);
    return phone_number;
}