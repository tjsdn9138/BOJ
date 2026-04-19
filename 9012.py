T = int(input())

for _ in range(T):
    gwal = input()
    while gwal:
        if "()" in gwal:
            gwal = gwal.replace("()", "")
        else:
            print("NO")
            break
    else:
        print("YES")