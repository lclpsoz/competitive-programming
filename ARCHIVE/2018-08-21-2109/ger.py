ar = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

print(58*2**10)
while (True):
    for k in range (58):
        print (str(10) + " " + str(k))
        for i in ar:
            print(i, end="")
        print()
    ar[9]+=1
    i = 9
    while (ar[i] > 1):
        ar[i] = 0
        ar[i-1] += 1
        i -= 1
        if (i < 0):
            break;
    if (i < 0):
        break;
