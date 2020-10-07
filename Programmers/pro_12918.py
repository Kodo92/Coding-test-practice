def solution(s):
    answer = False
    length = len(s)
    if length == 4 or length == 6 :
        if s.isdigit() == True :
            answer = True
    return answer