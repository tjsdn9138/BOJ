a = [0] * 30
for i in range(28):
    a[int(input())-1] += 1

print(a.index(0) + 1)
a[a.index(0)] += 1
print(a.index(0) + 1)