a = list(map(int, input().split()))
a.sort(reverse = True)

if a[0] == a[1] == a[2]:
    print(a[0] * 1000 + 10000)
elif a[0] != a[1] and a[1] != a[2] and a[2] != a[0]:
    print(a[0] * 100)
else:
    print(a[1] * 100 + 1000)