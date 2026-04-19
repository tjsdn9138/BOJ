n = int(input())
a = [input().split() for i in range(n)]

for i in range(n):
    print(f"Case #{i+1}: {int(a[i][0]) + int(a[i][1])}")