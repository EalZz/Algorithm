import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    E, S, M = map(int, input().split())
    year = 1

    while True:
        if ((year-E) % 15 == 0) and ((year-S) % 28 == 0) and ((year-M) % 19 == 0):
            break 
        year += 1
    
    print (year)

if __name__ == "__main__":
    solve()