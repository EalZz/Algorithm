import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    N = int(input())
    if N % 2 == 0 :
        print("CY")
    else :
        print("SK")


if __name__ == "__main__":
    solve()