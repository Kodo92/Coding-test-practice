# 프린터
# https://programmers.co.kr/learn/courses/30/lessons/42587

# 중요도가 높은 문서를 먼저 인쇄
# 1. 가장 앞 쪽의 대기 문서 1개를 꺼냄
# 2. 나머지 문서 중 꺼낸 문서보다 우선 순위가 높은 것이 있으면 꺼낸 문서를 다시 넣는다.
# 3. 아니면 j 인쇄

def solution(priorities, location):
    # 인덱스 리스트 생성
    # [0, 1, 2 ...] : 큐로 사용
    index_list = list(range(len(priorities)))

    # count번째 인쇄
    count = 1
    while True:
        # 1번 작업
        value = index_list.pop(0)

        # 2번 작업
        # 중요도는 1~9 범위이므로 value보다 우선순위가 큰 문서가 있는지 확인
        isFind = False
        for i in range(priorities[value]+1, 10):
            if i in priorities:
                isFind = True
                index_list.append(value)
                break

        # 2번 요건이 충족되어 value를 다시 집어넣는다.
        if isFind:
            continue
        
        priorities[value] = 0
        if value == location:
            break
        count+=1

    return count

print(solution([1,1,9,1,1,1],0))