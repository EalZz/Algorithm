import sys
from collections import deque
import math

#input = sys.stdin.readline 

def solve():
    n = int(input())
    count = 0
    five = n//5  
    two = 0  
    while True: 

        remain = (n - (5*five) - (2*two))
    
        if five < 0: 
            print(-1)
            break
        
        if remain == 0 : 
            print(five+two) 
            break 

        if remain % 2 == 1: five -= 1
        else: two = remain//2

if __name__ == "__main__":
    solve()