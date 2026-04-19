while True:
    n = int(input())
    k = []
    if n == -1:
        break
    for i in range(1, n):
        if n % i == 0:
            k.append(i)
    if sum(k) == n:
        print(n, "=", end = " ")
        for i in range(len(k)-1):
            print(k[i], end = " + ")
        print(k[-1])
    else:
        print(f"{n} is NOT perfect.")