from random import randint

n = randint (1, 15)
k = randint (1, 15)

print (n, k)
for i in range (k):
    print (randint (1, n), end = " ")