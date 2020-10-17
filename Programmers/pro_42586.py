# 기능 개발
# https://programmers.co.kr/learn/courses/30/lessons/42586?language=python3

def solution(progresses, speeds):
    # 배포 여부를 list에 boolean 자료형으로 생성
    isDistributes = [False for x in range(len(speeds))]

    answer = []

    # 모두 배포가 될 때 까지 반복한다.
    # 배포가 된 인덱스의 값은 True 이다.
    while isDistributes.count(False) != 0:

        # progresses 리스트를 순회하면서 speeds 만큼 더해준다.
        # 이미 100%를 초과한 경우엔 스킵한다.
        for i in range(len(progresses)):
            if progresses[i] >= 100:
                continue
            progresses[i] += speeds[i]

        # 배포가 되지 않은 인덱스 중 제일 앞의 인덱스를 얻어온다.
        starting_index = isDistributes.index(False)
        if progresses[starting_index] >= 100:
            count = 0
            # 시작 인덱스부터 끝까지 작업률이 100% 넘었는지 확인한다.
            for i in range(starting_index, len(speeds)):
                if progresses[i] >= 100:
                    isDistributes[i] = True
                    count += 1
                else:
                    break

            if count > 0 :
                answer.append(count)
              

    return answer

print(solution([93,30,55],[1,30,5]))