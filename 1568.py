N = int(input())
answer = 0

while N > 0:
    k = 1
    while k <= N:
        N -= k
        k += 1
        answer += 1
print(answer)