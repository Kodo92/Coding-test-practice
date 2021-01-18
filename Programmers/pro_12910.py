#나누어 떨어지는 숫자 배열
def solution(arr, divisor):
    answer = []

    for i in arr:
        if i % divisor == 0:
            answer.append(i)
    
    # element가 없는 경우 -1 삽입
    if len(answer) == 0:
        answer.append(-1)
    
    answer.sort()   # 리스트 정렬
    return answer