import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
A.sort()
M = int(input())
B = list(map(int, input().split()))

def b_search(data, target):
    start = 0
    end = len(data) - 1

    while start <= end:
        k = (start + end) // 2
        if data[k] == target:
            return 1
        elif data[k] < target:
            start = k + 1
        else:
            end = k - 1
    return 0

for i in B:
    print(b_search(A, i))