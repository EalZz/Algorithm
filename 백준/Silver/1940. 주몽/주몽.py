import sys
input = sys.stdin.readline

def solve():
    N = int(input())
    M = int(input())
    arr = sorted(list(map(int, input().split())))

    left = 0
    right = N - 1
    cnt = 0

    while left < right :
        s = arr[left] + arr[right]
        if s < M : left += 1
        elif s > M : right -= 1
        else : 
            cnt += 1
            left += 1
            right -= 1
    
    print(cnt)
        

if __name__ == '__main__':
    solve()