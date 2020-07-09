from math import sqrt

def crivo (n):
    primo = [1 for i in range (0, n+1)]
    primo[0] = 0
    primo[1] = 0
    n1 = int (sqrt(n)+1)
    for i in range (2, n1+1):
        if primo[i] == 1:
            print ("Removendo multiplos de " + str(i))
            for j in range (i*i, n+1, i):
                primo[j] = 0
            print (primo)

crivo (20)
