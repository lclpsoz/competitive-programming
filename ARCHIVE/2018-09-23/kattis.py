n = int(input())

ans = 0
two = 1
lst = []
while (n > 0):
    lst.append(n%2)
    n = int(n/2)
#print (lst)

lst.reverse()
for i in lst:
    if (i == 1):
        ans += two
    two *= 2
print (ans)
