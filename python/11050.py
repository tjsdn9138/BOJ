N, K = map(int, input().split())

def fcn(n, k):
    if k == 0 or k == n:
        return 1
    else:
        return fcn(n-1, k) + fcn(n-1, k-1)

print(fcn(N, K))