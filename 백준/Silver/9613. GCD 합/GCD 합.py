import sys
from collections import deque
import math

#input = sys.stdin.readline 

def solve():
    n=int(input())

    for i in range(n):
        arr=list(map(int, sys.stdin.readline().split()))
        ans=0
        for j in range(1,len(arr)):
            for k in range(j+1,len(arr)):
                ans+=math.gcd(arr[j],arr[k])

        print(ans)

if __name__ == "__main__":
    solve()