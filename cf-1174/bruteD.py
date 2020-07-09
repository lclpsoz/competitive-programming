
def check (lst, x):
    for i in range (len (lst)):
        for j in range (i, len(lst)):
            ax = 0
            for k in range (i, j+1):
                ax ^= lst[k]
            if (ax == 0 or ax == x):
                return False
    return True

ans = []

def dfs (n, p, lst, x):
    if (p == len(lst)):
        if (check (lst, x)):
           ans.append (lst[:])
           return True
    else:
        for i in range (1, 2**n):
            lst[p] = i
            if (dfs (n, p+1, lst, x)):
                return True



for n in range (1, 19):
    print ("n = ", n)
    for i in range (1, 2**n) :
        ans = []
        dfs (n, 0, [1]*i, 8)
        print (i, len (ans))
        print (ans)
        ans = []