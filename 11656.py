S = input()
List = [S]

while True:
    if len(S) > 1:
        List.append(S[1:])
        S = S[1:]
    elif len(S) == 1:
        List.append(S)
        S = ""
    else:
        break


List.pop()
List.sort()

for i in List:
    print(i)