import sys
import random

c = 1
x = 1
for i in range (1, 300000):
    c *= i
    while (c % 10 == 0):
        c /= 10
    print c%10
#for i in range (1, 20):
#    x = random.randint(1,49999)
#    print str(x) + " " + str(a[x])
