x, m = input().split(' ')
x = int(x)
m = int(m)

while (x > 0 or m > 0):
    y = 2*x
    print (x, y)
    for i in range (m):
        z = y
        y = y+x
        x = z
    print (x)
    x, m = input().split(' ')
    x = int(x)
    m = int(m)
