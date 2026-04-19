import sys
input = sys.stdin.readline

List = [True] * 246913
List[0] = List[1] = False
for i in range(2, int(246912 ** 0.5) + 1):
    if List[i]:
        for ii in range(i*i, 246913, i):
            List[ii] = False

while True:
    n = int(input())
    if n == 0:
        break
    print(sum(List[n+1:n*2+1]))