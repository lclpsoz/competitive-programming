a = 0
b = 1
aux = 4


s1 = []
s2 = []
s = 0
for i in range (2, 61):
    s += (i*b)/aux
    aux *= 2
    c = b
    b = a+b
    a = c
    s1.append (s)

a = 0
b = 1
aux = 2
bef = 0

s = 0
for j in range (2, 61):
    now = b * j
    s += (now - bef) * 1/aux
    bef = now
    aux *= 2
    c = b
    b = a+b
    a = c
    s2.append (s)

for i in range (len (s1)):
    print (str (s1[i]) + "\t" + str (s2[i]))
