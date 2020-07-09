from random import random
from math import ceil

arr = [0]*1000

for i in range(100000000):
    if (random() <= 0.5):
        arr[0]+=1
    else:
        arr[1]+=1
    if (random() < 0.5):
        arr[2]+=1
    else:
        arr[3]+=1

for i in range(12):
    print (str(i) + " " + str(arr[i]))
