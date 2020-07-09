from random import randint

n = 4095
s=[]
for i in range (n):
    s += chr (ord('a')+randint(0, 25))
    print (s[len(s)-1], end="")
print ("")
m = n
sw = []
for j in range(m):
    sw.append ([randint(1, n), randint (1, n)])

for p in sw:
    ax = s[p[0]-1]
    s[p[0]-1] = s[p[1]-1]
    s[p[1]-1] = ax

for c in s:
    print (c, end="")
print ("")

for i in range (1000):
    ss = list (input())
    for p in sw:
        ax = ss[p[0]-1]
        ss[p[0]-1] = ss[p[1]-1]
        ss[p[1]-1] = ax
    for c in ss:
        print (c, end="")
    print ("")