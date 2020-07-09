from random import random

n = 10
m = int (4 + int (round (random()*4 + 0.5)))
print (n)
print (m)
while m > 0:
    m -= 1
    v = int (round (random()*n + 0.5))
    u = int (round (random()*n + 0.5))
    print (str (v) + " " + str (u))
