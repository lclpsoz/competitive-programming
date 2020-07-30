from random import randint 

for x in range(2, 101):
    n = randint(2, 100)
    if randint(0, 1):
        b = randint(1, 20)
    else:
        b = randint(1, 100)
    k = randint(0, 99)
    x = randint(k+1, 100)
    print("%d %d %d %d" % (n, b, k, x))
    for i in range(n):
        print(randint(1, 9), end=' ')
    print('')