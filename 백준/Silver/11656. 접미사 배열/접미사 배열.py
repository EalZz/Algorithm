import sys
from collections import deque

#input = sys.stdin.readline 

def solve():
    s = str(input())
    list = []

    for _ in s:
        list.append(s)
        s = s[1:]

    list.sort()

    for i in list:
        print(i)
        

if __name__ == "__main__":
    solve()