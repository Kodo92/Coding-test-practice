# 정수 내림차순으로 배치하기
def solution(n):
    # n을 문자열로 변환
    s = str(n)
    
    # 내림차순 정렬
    s = sorted(s,reverse = True)
    
    # 리스트 문자열로 변환
    answer = ""
    for i in s:
        answer += i
    
    return int(answer)

    