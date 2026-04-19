T = int(input())
a = [input().split() for i in range(T)]
b = []

for j in range(T):
    b.append(int(a[j][0]) + int(a[j][1]))
for k in range(T):
    print(b[k])