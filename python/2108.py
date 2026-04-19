import sys
input = sys.stdin.readline

N = int(input())
Input = [int(input()) for _ in range(N)]
Input.sort(reverse = True)
Set = list(set(Input))
Set.sort(reverse = True)

List = [[x, Input.count(x)] for x in Set]

print(round(sum(x[0] * x[1] for x in List) / N))
print(Input[N // 2])

temp = sorted(List, key = lambda x : x[1])
if len(temp) == 1: print(List[0][0])
else:
    if temp[-1][1] == temp[-2][1]: print(temp[-2][0])
    else: print(temp[-1][0])

print(Input[0] - Input[N - 1])