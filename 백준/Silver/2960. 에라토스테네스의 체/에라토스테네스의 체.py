import sys
from collections import deque
import math

#input = sys.stdin.readline 

def solve():
    N, K = map(int,input().split())

    nums = [ i for i in range(2, N+1)]
    erase = []
    while len(nums) > 0:
        p = nums[0]     
        temp = []
        for i in range(len(nums)):
            if nums[i] % p == 0: erase.append(nums[i])
            else: temp.append(nums[i])            
        nums = temp
    
    print(erase[K-1])

if __name__ == "__main__":
    solve()