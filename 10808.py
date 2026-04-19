s = input()

List = [0 for _ in range(26)]

for i in range(len(s)):
    List[ord(s[i]) - 97] += 1
    
for i in List:
    print(i, end = " ")