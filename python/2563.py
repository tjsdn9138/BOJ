List = [0 for _ in range(10000)]
N = int(input())
n = [list(map(int, input().split())) for _ in range(N)]
for i in range(N):
    s = n[i][0] + n[i][1] * 100
    for ii in range(10):
        for iii in range(10):
            List[(s-1) + (ii*100) + (iii)] = 1
print(List.count(1))