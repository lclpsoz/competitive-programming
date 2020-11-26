from random import randint

n = randint (1000, 2000)
# print (n)
s = ""
for i in range (n):
    s += str(randint (0, 1))
print (s)

def check (l, r):
    for md in range (l+1, r):
        j = 1
        while (md-j >= l and md+j <= r):
            if (s[md-j] == s[md] and s[md+j] == s[md]):
                return True
            j+=1

    return False

ans = 0
for i in range (n):
    for j in range (i+2, n):
        ans += check (i, j)
print (ans)