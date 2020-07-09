def calc (n):
    r = 1
    for i in range (1, n+1):
        r *= i
    return r

line = raw_input().split(' ')
a = int(line[0])
b = int(line[1])

arr = [-1]*1790
arr[2] = 2
x = 2
for i in range (3, 1778):
    arr[i] = arr[i-1]*i

while (a or b):
    t = input()
    z = int(a+1-b)
    if (z > 1777 or arr[z] > t):
        print "descartado"
    else:
        print arr[z]
    line = raw_input().split(' ')
    a = int(line[0])
    b = int(line[1])
