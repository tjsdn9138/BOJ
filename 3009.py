a = [list(map(int, input().split()))for _ in range(3)]
b = []
c = []

for i in range(3):
    b.append(a[i][0])
    c.append(a[i][1])
b_min = min(set(b), key = b.count)
c_min = min(set(c), key = c.count)

print(b_min, c_min)