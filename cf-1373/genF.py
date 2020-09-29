from random import randint
t = 1000000
print(t)
for i in range(t):
    n = randint(2, 10)
    print(n)
    for i in range(n):
        print(randint(1, 2*n), end=' ')
    print('')
    for i in range(n):
        print(randint(1, 2*n), end=' ')
    print('\n')