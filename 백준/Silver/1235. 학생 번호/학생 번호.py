N = int(input())
A = []

for _ in range(N):
    A.append(str(input()).strip())
    
count = 1
start = len(A[0]) - 1
end = len(A[0])

while start >= 0:
    ans = []
    for i in range(N):
        ans.append(A[i][start:end])
    if len(set(ans)) == N:
        break
    else:
        count += 1
    start -= 1
    
print(count)