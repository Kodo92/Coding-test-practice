# 문자열 내 마음대로 정렬하기
# https://programmers.co.kr/learn/courses/30/lessons/12915

# 각 문자열의 인덱스 n번 글자 기준으로 오름차순 정렬
# 파이썬의 정렬은 Stability가 보장된다.

from operator import itemgetter

def solution(strings, n):
    
    # n번째 인덱스가 같은 문자열일 경우 '오름차순'으로 정렬을 요구했으므로 우선 정렬해 오름차순으로 만든다.
    # Stability를 이용
    strings.sort()

    # itemgetter(n)은 n번째의 값을 꺼낸다. 
    # https://docs.python.org/ko/3/library/operator.html#operator.itemgetter
    answer = sorted(strings, key=itemgetter(n))

    return answer