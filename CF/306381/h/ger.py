n = 1000
m = (n*(n-1))//2
print(n, m+n)
for i in range(n):
    print(1, end=' ')
print('')
for i in range(1, n+1):
    for j in range(i+1, n+1):
        print(i, j, 1)
for i in range(1, n+1):
    print(i, i, 1)
