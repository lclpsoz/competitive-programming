from math import log10
n = int(input())
while (n > 0):
    x, y = map(int, input().split(' '))
    x = x**y
    ans = 0
    while (x > 0):
        ans += 1
        x = int(x/10)
    print(ans)
    n-=1
