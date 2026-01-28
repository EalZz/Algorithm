import sys
N = int(sys.stdin.readline())
K = list(map(int, sys.stdin.readline().strip().split())) 
K = set(K)
K = list(K)
K.sort()
for i in range(len(K)):
    print(K[i], end=' ')