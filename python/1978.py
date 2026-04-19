N = int(input())
a = list(map(int, input().split()))
n = 0

for i in a:
    k = 0
    if i == 1:
        continue
    for ii in range(2, i):
        if i % ii == 0:
            k = 1
    if k == 1:
        continue
    n += 1
print(n)