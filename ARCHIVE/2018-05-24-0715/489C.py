st = input().split()
a = int(st[0])
b = int(st[1])

if (b == 0):
    if (a == 1):
        print ("0 0")
    else:
        print ("-1 -1")
elif ((9*a) < b):
    print ("-1 -1")
else:
    mini = int(10**(a-1))
    aux = b
    b-=1
    i = 0
    while (b > 9):
        mini += 9*(10**i)
        i+=1
        b-=9
    mini += b*(10**i)

    b = aux
    i = a-1
    maxi = 0
    while (b > 9):
        maxi += 9*(10**i)
        i-=1
        b-=9
    maxi += b*(10**i)


    print(str(mini) + " " + str(maxi))

