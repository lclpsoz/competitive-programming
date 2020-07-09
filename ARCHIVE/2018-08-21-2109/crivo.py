def crivo(n):
    inteiros = [i for i in range(2, n)]
    i = 0
    while i < len(inteiros):
        x = inteiros[i]
        #print (inteiros)
        for k in range(x*x, n, x):
            #print (k)
            if (k in inteiros):
                inteiros.remove (k)
        i+=1
    return inteiros



print (crivo(100))
