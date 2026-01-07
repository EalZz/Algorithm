import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    line = sys.stdin.readline().strip()
    if not line: return
    S = int(line)
    
    N = 1
    while N * (N + 1) // 2 <= S :
        N += 1
    print(N - 1)

if __name__ == "__main__":
    solve()