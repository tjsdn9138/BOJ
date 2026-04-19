n = int(input())
n_ = n % 5
n_5 = n // 5
n_3 = 0

while n_ <= n:
    if n_ % 3 == 0:
        n_3 = n_ // 3
        print(n_5 + n_3)
        break
    else:
        n_ += 5
        n_5 -= 1
else:
    print(-1)