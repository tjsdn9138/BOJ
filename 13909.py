import sys
input = sys.stdin.readline
i = 1

N = int(input())
answer = 0

while i*i <= N:
    answer += 1
    i += 1

sys.stdout.write(str(answer))