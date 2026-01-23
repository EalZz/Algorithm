import sys
from collections import deque
import math

#input = sys.stdin.readline 

def solve():
    n = int(input())
    cards = deque(list(range(1, n + 1)))
    ans = []

    while cards :
        card = cards.popleft()
        ans.append(card)

        if cards :
            card = cards.popleft()
            cards.append(card)
    
    print(*ans)

if __name__ == "__main__":
    solve()