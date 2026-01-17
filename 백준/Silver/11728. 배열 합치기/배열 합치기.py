import sys

input = sys.stdin.readline

def solve():
    N, M  = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    ans = A + B
    ans.sort()

    print(*ans)

if __name__ == '__main__' :
    solve()