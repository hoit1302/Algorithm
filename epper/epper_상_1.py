import sys


# [*주의] 실제 epper 시험에서는 solution 함수의 내용만 채워주시면 됩니다 !!!!!
# 추가로 사용하고 싶은 함수를 만들 수 있습니다.
# 사용하고 싶은 라이브러리가 있다면 선언하고 사용하면 됩니다.
def solution(N, money):
    for i in range(1, N):
        for j in range(i+1):
            if j == 0: # 가장 왼쪽
                money[i][j] += money[i-1][0]
            elif i == j: # 가장 오른쪽
                money[i][j] += money[i-1][j-1]
            else: # 가운데
                money[i][j] += max(money[i-1][j-1], money[i-1][j])
    return max(money[N-1]) # 맨 아래에 도착해야 하므로 맨 아랫줄의 값 중 가장 큰 합을 정답으로 반환한다.


N = int(input())
money = []
for _ in range(N):
    money.append(list(map(int, sys.stdin.readline().rstrip().split())))
print(solution(N, money))
