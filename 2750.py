N = int(input())

a = [int(input()) for _ in range(N)]
a = sorted(list(set(a)))

for i in range(len(a)):
    print(a[i])