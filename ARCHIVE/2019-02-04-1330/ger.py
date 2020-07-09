n = 4000
m = 12
print (str (n) + " " + str (m))
for i in range (n):
    for j in range (m):
        if (i == j):
            print ("0", end=" ")
        else:
            print ("1", end=" ")
    print ("")
