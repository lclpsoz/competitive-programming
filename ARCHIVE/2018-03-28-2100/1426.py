import sys
m = input ()

def constr (n):
    lst.append ([])

    arr = raw_input().split(' ')
    arr = [int(x) for x in arr]
    lst.append ([]) #lst[4]
    for i in range (0, n+1):
        if (i%2==1):
            lst[n].append(0)
        else:
            lst[n].append(arr[i/2])
    for i in range (1, n+1, 2):
        lst[n][i] = (lst[n-2][i-1]-lst[n][i-1]-lst[n][i+1])/2
    for i in range (0, n):
        lst[n-1].append (lst[n][i]+lst[n][i+1])

for i in range (0, m):
    lst = []
    lst.append ([input()])

    constr (2)
    constr (4)
    constr (6)
    constr (8)
    for i in range (0, len(lst)):
        now = lst[i]
        for j in range (0, len(now)):
            if (j < len (now)-1):
                sys.stdout.write (str(now[j]) + " ")
            else:
                sys.stdout.write (str(now[j]))
        print ""
    del lst[:]
