L = []

while(True):
    A, B = map(int, input().split())
    if A + B == 0:
        break
    L.append(A + B)

for i in range(len(L)):
    print(L[i])