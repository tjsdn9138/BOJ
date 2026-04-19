X = int(input())
n = int(input())
a = list(input().split() for j in range(n))
b = 0
for i in range(n):
    b += int(a[i][0]) * int(a[i][1])
if X == b:
    print("Yes")
else:
    print("No")