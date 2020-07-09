from random import random

n = int(random()*13)+2
m = n-1
MAXN = int(2**64 - 1)

print(n)

for i in range (n):
    print(int(random()*MAXN))
