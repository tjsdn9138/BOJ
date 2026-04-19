List = ["/", "-", "\\", "(", "@", "?", ">", "&", "%"]

while True:
    n = input()
    temp = [x for x in n]
    answer = 0
    k = 0
    if n == "#":
        break
    for i in range(-1, -len(temp)-1, -1):
        answer += (List.index(temp[i])-1) * (8**k)
        k += 1
    print(answer)