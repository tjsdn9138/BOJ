N, M = map(int, input().split())
answer = 0
min_pac = 1001
min_nat = 1001

for _ in range(M):
    temp = list(map(int, input().split()))
    min_pac = min(min_pac, temp[0])
    min_nat = min(min_nat, temp[1])

if min_pac < min_nat * 6:
    answer += (N // 6) * min_pac
    N %= 6
    answer += min((N * min_nat), min_pac)
else:
    answer = N * min_nat

print(answer)