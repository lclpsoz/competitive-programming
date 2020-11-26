from random import randint


A = 3
n = randint (2, 10)
print (n)
for i in range (n):
    s = randint (1, 10)
    for i in range (s):
        print (chr(ord('a')+randint(0, A-1)), end ="")
    print ("")