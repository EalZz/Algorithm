import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    X = int(input())
    sticks = [64, 32, 16, 8, 4, 2, 1]
    cnt = 0

    for stick in sticks :
        if X >= stick :
            cnt += 1
            X -= stick
        if X == 0 :
            break
    
    print(cnt)

if __name__ == "__main__":
    solve()