N, M = map(int, input().split())
Dict = {}

for _ in range(N):
    site, password = input().split()
    Dict[site] = password

for _ in range(M):
    print(Dict[input()])