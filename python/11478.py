S = input()
List = []
for i in range(1, len(S)+1):
    for ii in range(len(S)-i+1):
        List.append(S[ii:ii+i])
print(len(set(List)))