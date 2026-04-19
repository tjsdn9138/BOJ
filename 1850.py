from math import gcd

a, b = map(int, input().split())

count = gcd(a, b)

for _ in range(count):
  print(1, end = "")