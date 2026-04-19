a = [int(input()) for i in range(2)]

if a[0] > 0:
    print("41"[a[1] > 0])
else:
    print(2 if a[1] > 0 else 3)