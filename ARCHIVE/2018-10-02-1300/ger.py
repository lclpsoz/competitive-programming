from random import random

tests = 10000

print(tests)

for ii in range (tests):
    r = round(random()*60)+3
    c = round(random()*60)+3
    print (str (r) + " " + str (c))
    for i in range (r):
        for j in range (c):
            if (round(random()) == 0):
                print (1, end = " ")
            else:
                print(2, end = " ")
        print ("")
print()
