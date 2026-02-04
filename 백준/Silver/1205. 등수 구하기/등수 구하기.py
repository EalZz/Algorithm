scoreList = []
boundary = 1
rank = 1

N, tScore, P = map(int, input().split())

if N != 0:
    scoreList = [int(x) for x in input().split()]

for i in range(N):
    if scoreList[i] > tScore:
        boundary += 1
        rank += 1
    elif scoreList[i] == tScore:
        boundary += 1

if boundary > P:
    print(-1)
else:
    print(rank)