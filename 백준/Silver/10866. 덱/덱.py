import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    line = input().strip()
    if not line: return
    N = int(line)

    dq = deque()

    for _ in range(N):
        command = input().split()
        if not command: continue
        
        order = command[0]

        if order == "push_front":
            dq.appendleft(command[1])
        elif order == "push_back":
            dq.append(command[1])
        elif order == "pop_front":
            print(dq.popleft() if dq else -1)
        elif order == "pop_back":
            print(dq.pop() if dq else -1)
        elif order == "size":
            print(len(dq))
        elif order == "empty":
            print(0 if dq else 1)
        elif order == "front":
            print(dq[0] if dq else -1)
        elif order == "back":
            print(dq[-1] if dq else -1)

if __name__ == "__main__":
    solve()