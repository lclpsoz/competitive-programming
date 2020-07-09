import random

n = random.randint (1, 15)
s = ""
alpha = "abcdefghijklmnopqrstuvwxyz"
for i in range (n):
    s += random.choice (alpha)

print (s)
q = random.randint (int(n/2) + 1, 3*n)
print (q)
for i in range (q):
    o = random.randint (1, 2)
    print (o, end = " ")
    if (o == 1):
        print (str(random.randint (1, n)) + " " + random.choice (alpha))
    else:
        x = random.randint (1, n)
        y = random.randint (1, n)
        if (x > y):
            z = x
            x = y
            y = z
        print (x, y)

