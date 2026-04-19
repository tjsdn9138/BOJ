T = int(input())

for ii in range(T):
    num, a = input().split()
    for i in range(len(a)-1):
        print(a[i] * int(num), end = "")
    print(a[len(a)-1] * int(num))