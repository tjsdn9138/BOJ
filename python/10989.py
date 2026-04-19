import sys
input = sys.stdin.readline

N = int(input())
B = [0] * (10001)

for _ in range(N):
    B[int(input())] += 1

for i in range(len(B)):
    if B[i] != 0:
        for _ in range(B[i]):
            print(i)