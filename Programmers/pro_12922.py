# 수박수박수박수박수박수?
#   https://programmers.co.kr/learn/courses/30/lessons/12922

# n이 짝수 = 수박
# n이 홀수 = 끝에서 하나 빼주기 위해서 int(n/2)+1함

def solution(n):
    answer = '수박'
    quot = n/2
    if quot > int(quot):
        quot += 1
    quot = int(quot)        
        
    answer *= quot
    if n%2 != 0:
        return answer[:-1]
    else:
        return answer