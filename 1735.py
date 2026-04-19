from math import gcd

A = list(map(int, input().split()))
B = list(map(int, input().split()))
lcm = A[1] * B[1] // gcd(A[1], B[1])
son = A[0] * (lcm // A[1]) + B[0] * (lcm // B[1])
k = gcd(son, lcm)
son //= k
lcm //= k

print(son, lcm)