n = int(input())

x = 1
for i in range (1, 210000):
    x *= i
    if (x > n):
        ans = i
        break

print (ans)
