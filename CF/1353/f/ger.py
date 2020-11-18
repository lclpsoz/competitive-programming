from random import randint
print(1)
print(100, 100)
for i in range(1, 101):
    for j in range(1, 101):
        print(randint(1, 10**15), end=' ')
    print('')
