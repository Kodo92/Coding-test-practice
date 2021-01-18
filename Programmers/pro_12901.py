# 2016년
# https://programmers.co.kr/learn/courses/30/lessons/12901?language=python3

import datetime

def solution(a,b):
    days = 'MON TUE WED THU FRI SAT SUN'.split()
    return days[datetime.datetime(2016, a, b).weekday()]