import random

for j in range (1000):
    n = random()*100
    for i in range (n):
        p = int(round(random.random()))
        c = "PR"[p]
        print (c, end="")
    print ("")
