from collections import Counter

N = int(input())
List = [input() for _ in range(N)]
counter = Counter(List)

print(sorted(counter.items(), key = lambda x : (-x[1], x[0]))[0][0])