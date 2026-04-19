M, N = map(int, input().split())

for n in range(M, N+1):
    if n < 2:
        continue
    if n == 2:
        print(2)
    if n % 2 == 0:
        continue
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            break
    else:
        print(n)