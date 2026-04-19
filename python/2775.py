T = int(input())

List = [[0 for _ in range(15)] for _ in range(15)]

for i in range(15):
    List[0][i] = i
    List[i][1] = 1

for i in range(1, 15):
    for ii in range(1, 15):
        List[i][ii] = List[i][ii - 1] + List[i - 1][ii]

for _ in range(T):
    k = int(input())
    n = int(input())
    print(List[k][n])