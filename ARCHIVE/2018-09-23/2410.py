n = int(input())

MAXN = int(1e6+10)

a = [False]*MAXN;
for i in range (n):
    x = int(input())
    a[x] = True

ans = 0
for i in a:
    if (i == True):
        ans += 1

print (ans)
