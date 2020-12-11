from random import randint

n = 5
print(n)
for i in range(n):
    for j in range(n):
        print(randint(0, 1), end=' ')
    print('')