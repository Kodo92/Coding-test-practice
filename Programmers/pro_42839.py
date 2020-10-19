# 소수 찾기 (완전 탐색)
# https://programmers.co.kr/learn/courses/30/lessons/42839?language=python3

# 조합으로 가능한 숫자들을 추려낸다
# 이 때, 중복되는 숫자와 1이하의 숫자는 제외한다.

from itertools import permutations

def IsPrime(number):
    for i in range(2,number):
        if number % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    duplication_set = set()
    for i in range(1,len(numbers)+1):
        result = permutations(numbers,i)
        for j in result:
            test_number = int("".join(j))
            # 1 이하 숫자 제거
            if test_number <= 1:
                continue
            # 중복 체크
            if test_number not in duplication_set:
                duplication_set.add(test_number)
                if IsPrime(int("".join(j))):
                    answer += 1
    return answer


print(solution("011"))