a = []
for i in range(9):
    a += list(map(int, input().split()))

n = a.index(max(a)) + 1
print(max(a))
if n%9 != 0:
    print((n//9)+1, n%9)
else:
    print((n//9), 9)