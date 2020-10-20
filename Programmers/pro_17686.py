# [3차] 파일명 정렬
# https://programmers.co.kr/learn/courses/30/lessons/17686?language=python3

# 1. 정규 표현식을 이용해 문자열 분해
# 2. 0, 1번 인덱스 순서로 정렬

import re

def solution(files):
    temp = [re.split("([0-9]{1,5})",s) for s in files]
    result = sorted(temp,key = lambda x: (x[0].lower(), int(x[1])))
    return [''.join(s) for s in result]

solution(["img123333.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])