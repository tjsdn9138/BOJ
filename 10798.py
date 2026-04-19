List = [list(input()) for _ in range(5)]

while len(List) > 0:
    List = [i for i in List if len(i) > 0]
    for ii in range(len(List)):
        print(List[ii].pop(0), end = "")