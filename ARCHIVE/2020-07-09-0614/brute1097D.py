from math import sqrt

n = int (input())

divs = []
mp = {}
for i in range (1, int (sqrt (n))+1):
    if (n%i == 0):
        divs.append (i)
        if (i != n//i):
            divs.append (n//i)
mp[n] = divs

divs.sort()
print (divs)

for k in range (10):
    for p in range (len (divs)):
        n = divs[p]
        if (n in mp):
            continue
        now = []
        for i in range (1, int (sqrt (n)) + 1):
            if (n%i == 0):
                now.append (i)
                if (i != n//i):
                    now.append (n//i)
        now.sort()
        print ("divs of {}".format (n))
        print (now, sep="\t")
        print ("")
        for x in now:
            divs.append (x)
        mp[n] = now