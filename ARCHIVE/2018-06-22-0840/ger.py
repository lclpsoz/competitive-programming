import random
from math import ceil

n = ceil(random.random()*10)
print (n)
for i in range(n):
    for j in range(n):
        print(ceil(random.random()*100), end=" ")
    print()
