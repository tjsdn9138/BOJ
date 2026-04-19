while True:
    List = list(map(int, input().split()))
    List.sort()

    if List[0] == List[1] == List[2] == 0:
        break

    if List[0]**2 + List[1]**2 == List[2]**2:
        print("right")
    else:
        print("wrong")