b = 5
n = 100
v = 0
for i in range (1, n):
    if (i == 1):
        v += 1 / b
    else:
        qnt = 11
        twos = 2**(i-1) - 1
        qnt += twos*3
        v += (qnt*i) / (b**i)
        print ("qnt: " + str (qnt))
    print (v)
