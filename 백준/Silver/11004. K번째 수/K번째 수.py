import sys
from collections import deque

input = sys.stdin.readline 

def solve():
    N, K = map( int, input().split() )

    arr = list( map( int, input().split()))

    arr.sort()

    print(arr[K-1])
        

if __name__ == "__main__":
    solve()