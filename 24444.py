import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = {x : [] for x in range(1, N+1)}
visited = {x : 0 for x in graph.keys()}
visited[R] = 1
que = [R]
k = 2
index = 0

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in graph:
    graph[i].sort()

while index < len(que):
    current = que[index]
    index += 1
    for next in graph[current]:
        if not visited[next]:
            visited[next] = k
            k += 1
            que.append(next)

for i in visited.values():
    print(i)