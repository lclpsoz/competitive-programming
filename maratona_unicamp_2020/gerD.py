from random import randint

n = randint(1, 10)
m = randint(0, n)
print(n, m)
for i in range(n):
    print(randint(1, 10), end=" ")
print("")