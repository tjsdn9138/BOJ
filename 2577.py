a = [int(input()) for i in range(3)]
n = a[0] * a[1] * a[2]

for i in range(10):
    print(str(n).count(str(i)))