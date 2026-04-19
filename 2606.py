computer = int(input())
match = int(input())
graph = {x : [] for x in range(1, computer+1)}

for _ in range(match):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(graph: dict, start: int):
    visited = {x : False for x in graph.keys()}
    visited[start] = True
    que = [start]
    while que:
        temp = que.pop(0)
        for i in graph[temp]:
            if not visited[i]:
                visited[i] = True
                que.append(i)
    return list(visited.values()).count(True)

print(bfs(graph, 1) - 1)