from math import gcd

N = int(input())
List = [int(input()) for _ in range(N)]
minus = [List[x+1] - List[x] for x in range(len(List)-1)]
result = 0
Gcd = minus[0]
for i in minus:
    Gcd = gcd(Gcd, i)
for i in minus:
    result += i // Gcd - 1

print(result)