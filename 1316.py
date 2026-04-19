N = int(input())
List = [input() for _ in range(N)]
answer = N

for word in List:
    for i in range(len(word)):
        if word.count(word[i]) >= 2:
            if word.rindex(word[i]) - word.index(word[i]) + 1 != word.count(word[i]):
                answer -= 1
                break           

print(answer)