import math
w, h, x, y, p = map(int, input().split())

# 반지름, 각 원의 중심 좌표
r = h / 2
c1x, c1y = x, y+r
c2x, c2y = x+w, y+r

count = 0 # 링크 안에 있는 사람 수 

for _ in range(p):
  px, py = map(int, input().split())

  # 각 원의 중심에서의 거리
  d1 = math.sqrt((c1x - px) ** 2 + (c1y - py) ** 2)
  d2 = math.sqrt((c2x - px) ** 2 + (c2y - py) ** 2)

  if d1 <= r or d2 <= r:
    count += 1
  elif x <= px <= x+w and y <= py <= y+h:
    count += 1

print(count)