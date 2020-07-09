a = []
for i in range(100000):
    a.append(int(input()))

#for x in a:
#    print (x)

lim = 99
for st in range (100):
    pos = st
    ans = 0
    for x in a:
        if (x == -1 and pos == -1):
            ans += 1
        elif (x == 1 and pos == lim):
            ans += 1
        else:
            pos += x
    print (str(st) + ": " + str(ans))
