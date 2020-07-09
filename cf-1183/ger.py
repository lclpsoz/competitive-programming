from random import randint
print (100, 100000000000000)
for i in range (100):
    #print (chr (ord ('a') + i%26), end="")
    #print (chr (ord ('a')), end="")
    print (chr (ord ('a')+randint(0, 25)), end="")
print ("")
