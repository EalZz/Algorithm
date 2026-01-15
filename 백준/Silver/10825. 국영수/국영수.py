import sys
from collections import deque

#input = sys.stdin.readline 

def solve():
    n = int(input())
    list = []
    for _ in range(n): list.append(input().split())
    
    list.sort(key = lambda a: (-int(a[1]), int(a[2]), -int(a[3]), a[0]))

    for i in list : print(i[0])
        

if __name__ == "__main__":
    solve()