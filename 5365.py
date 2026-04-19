N = int(input())

List = list(input().split())

print(List[0][0], end = "")
for i in range(1, N):
    if len(List[i]) < len(List[i - 1]): print(" ", end = "")
    else: print(List[i][len(List[i - 1]) - 1], end = "")