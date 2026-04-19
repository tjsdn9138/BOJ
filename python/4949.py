while True:
    n = input()
    List = []

    if n == ".":
        break

    for i in n:
        if i == "(" or i == "[":
            List.append(i)
        elif List and i == ")":
            if List[-1] == "(":
                List.pop()
            else:
                print("no")
                break
        elif List and i == "]":
            if List[-1] == "[":
                List.pop()
            else:
                print("no")
                break
        elif not List and (i == "]" or i == ")"):
            print("no")
            break
    else:
        if not List:
            print("yes")
        else:
            print("no")