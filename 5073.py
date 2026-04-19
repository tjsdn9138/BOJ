while True:
    n = list(map(int, input().split()))
    n.sort()
    if n == [0, 0, 0]:
        break
    if n[0] + n[1] > n[2]:
        if n[0] == n[1] == n[2]:
            print("Equilateral")
        elif n[0] == n[1] or n[1] == n[2] or n[2] == n[0]:
            print("Isosceles")
        else:
            print("Scalene")
    else:
        print("Invalid")