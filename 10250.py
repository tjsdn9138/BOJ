T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    a = []
    for ii in range(1, W+1):
        for iii in range(1, H+1):
            a.append(iii * 100 + ii)
    print(a[N-1])