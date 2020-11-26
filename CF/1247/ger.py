x = 100
d = 20
dd = 2
while (x < 1e19):
    print (x - d - d//2, x + d, sep = " ")
    x *= 10
    d = int (d*dd)
    dd *= 0.93
