# K번째 수
# https://programmers.co.kr/learn/courses/30/lessons/42748?language=python3

def solution(array, commands): 
    answer = []
    for i in range(len(commands)):
        copy = array[commands[i][0]-1:commands[i][1]]
        copy.sort()
        answer.append(copy[commands[i][2]-1])
    return answer