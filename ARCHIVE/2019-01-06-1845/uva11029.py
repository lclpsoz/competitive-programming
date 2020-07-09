from math import log10

b = 235234
p = 10000001
bb = b
pp = p

#n1 = b**p
#while (log10 (n1) > 18):
#    n1 = n1 // 10
#print ("n1: " + str (n1))

n2 = 1
for i in range (p):
    n2 *= b
    while (log10 (n2) > 9):
        n2 = n2 // 10
print ("n2: " + str (n2))

n3 = 1
while (p > 0):
    if (p%2 == 1):
        n3 = n3 * b
    b = b * b
    p = p // 2
    while (log10 (n3) > 9):
        n3 = n3 // 10
    while (log10 (b) > 9):
        b = b // 10
print ("n3: " + str (n3))

n4 = 1
p = pp
b = bb
while (p > 0):
    if (p%2 == 1):
        n4 = n4 * b
    b = b * b
    p = p // 2
    while (log10 (n4) > 18):
        n4 = n4 // 10
    while (log10 (b) > 18):
        b = b // 10
print ("n4: " + str (n4))

n5 = 1
p = pp
b = bb
while (p > 0):
    if (p%2 == 1):
        n5 = n5 * b
    b = b * b
    p = p // 2
    while (log10 (n5) > 28):
        n5 = n5 // 10
    while (log10 (b) > 28):
        b = b // 10
print ("n5: " + str (n5))
