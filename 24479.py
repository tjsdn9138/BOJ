import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = {x : [] for x in range(1, N+1)}

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph.values():
    i.sort()

def dfs(graph: dict, start: int):
    k = 1
    visited = {x : 0 for x in graph.keys()}
    def search(n):
        nonlocal k
        visited[n] = k
        k += 1
        for next in graph[n]:
            if not visited[next]:
                search(next)
    search(start)
    
    for i in visited.values():
        print(i)

dfs(graph, R)