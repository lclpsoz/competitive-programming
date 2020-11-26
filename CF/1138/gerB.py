import random

n = random.randint (2, 15)
if (n%2 == 1):
    n+=1

print (n)
for i in range (n):
    if (random.random() > 0.5):
        print ('1', end="")
    else:
        print ('0', end="")
print ("")
for i in range (n):
    if (random.random() > 0.5):
        print ('1', end="")
    else:
        print ('0', end="")
print ("")
