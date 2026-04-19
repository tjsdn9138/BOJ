N = int(input())

List = list(input().split())
LIST = list(input().split())

list_ = list(set(List) - set(LIST))

print(list_[0])