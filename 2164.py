import sys
input = sys.stdin.readline

List = list(range(1, int(input())+1))
start = 0

while len(List) - start > 1:
    start += 1
    List.append(List[start])
    start += 1
else:
    print(List[start])