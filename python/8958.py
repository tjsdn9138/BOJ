T = int(input())


for i in range(T):
    a = input()
    n = 0
    score = 0
    for ii in range(len(a)):
        if a[ii] == "O":
            n += 1
            score += n
        else:
            n = 0
    print(score)
