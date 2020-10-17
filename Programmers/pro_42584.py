# 주식 가격
# https://programmers.co.kr/learn/courses/30/lessons/42584?language=python3

# 단순히 index +1 부터 -1까지 prices[index]보다 큰 값의 개수 찾기

def solution(prices):
    answer = []
    prices_length = len(prices)
    for i in range(prices_length):
        count = 0
        for j in range(i+1,prices_length):
            count+=1
            if prices[i] > prices[j]:
                break
        answer.append(count)
    return answer

print(solution([1,2,3,2,3]))