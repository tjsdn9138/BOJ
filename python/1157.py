from collections import Counter

n = input().upper()
counter = Counter(n)
most_common = [i for i, ii in counter.items() if ii == max(counter.values())]

if len(most_common) != 1:
    print("?")
else:
    print(most_common[0])