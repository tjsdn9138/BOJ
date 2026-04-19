M = int(input())
N = int(input())
l = list(range(M, N+1))
if 1 in l:
    l.remove(1)


for i in range(M, N+1):
    for ii in range(2, int(i**0.5)+1):
        if i % ii == 0:
            l.remove(i)
            break
if len(l) != 0:
    print(sum(l))
    print(min(l))
else:
    print(-1)