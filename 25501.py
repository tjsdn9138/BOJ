def recursion(s, l, r):
    global k
    if l >= r:
        return 1
    elif s[l] != s[r]:
        return 0
    else:
        k += 1
        return recursion(s, l+1, r-1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

T = int(input())
S = [input() for _ in range(T)]
for i in S:
    k = 1
    print(isPalindrome(i), k)