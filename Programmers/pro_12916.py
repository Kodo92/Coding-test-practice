#문자열 내 p와 y의 개수
def solution(s):
    # 문자열 소문자 변경
    s = s.lower()
        
    if s.count('p') == s.count('y'):
        return True
    else:
        return False
        