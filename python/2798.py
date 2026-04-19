N, M = map(int, input().split())
l = list(map(int, input().split()))
answer = 0

for i in l:
    for ii in l:
        for iii in l:
            if i + ii + iii <= M:
                if i == ii or ii == iii or iii == i:
                    continue
                if i + ii + iii > answer:
                    answer = i + ii + iii
print(answer)