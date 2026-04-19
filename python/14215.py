n = sorted(list(map(int, input().split())))

if n[0] + n[1] > n[2]:
    print(sum(n))
else:
    print((n[0]+n[1])*2-1)