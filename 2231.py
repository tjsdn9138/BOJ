n = int(input())
a = 0

for i in range(1, n+1):
    k = sum(map(int, str(i)))
    if k+i == n:
        a = i
        break
print(a)