from random import random

ax = 1
for i in range (1, 100001):
    ax *= i
    if (random() < 0.01001):
        print (str (i) + " " + str (ax))
