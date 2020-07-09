t = input ()
for i in range (0, t):
    n = input ()
    ans = 0
    while (n):
        if (n % 2 == 1):
            ans += 1
        n /= 2;
    print (ans)
