#가운데 글자 가져오기
def solution(s):
    answer = ''
    
    # 문자열이 짝수인 경우 2개 출력
    if len(s) % 2 == 0:
        a = int(len(s)/2 - 1)
        answer = s[a] + s[a+1]
    else:
        a = int(len(s)/2)
        answer = s[a]

    return answer