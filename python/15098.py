List = list(input().split())
_List = list(set(List))

if len(List) == len(_List): print("yes")
else: print("no")