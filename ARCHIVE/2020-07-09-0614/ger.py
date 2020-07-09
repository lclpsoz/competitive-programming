import random

random.seed (3)
n = 4
a = [random.randint (1, 10) for i in range (n)]
print (a)
vals = []

for i in range (1, n-1):
    for j in range (0, i):
        for k in range (i+1, n):
            vals.append ((a[j] + a[k] - a[i], j, i, k))
            print (i, j, k, vals[-1])

st = a
goal = []
for v in st:
    goal.append (v)
for i in range (1, n-1):
    goal[i] = random.choice (vals)
print (goal)

vis = []
def dfs (now):
    #print ("now", now)
    #print (vis)
    if (now in vis):
        return False
    vis.append (now)
    if (now == goal):
        return True
    #print (now, goal)
    for i in range (1, n-1):
        #print (now, i)
        ax = []
        for v in now:
            ax.append (v)
        ax[i] = ax[i-1] + ax[i+1] - ax[i]
        if (dfs (ax)):
            print (i+1)
            return True

    return False

print (dfs (a))
print ("Valid vals:")
for v in vals:
    print (v)

arr = []
for i in range (n):
    arr.append (set())
for l in vis:
    for i in range (1, n-1):
        arr[i].add (l[i])
    # print (l)
for i in range (1, n-1):
    print (i, end=": ")
    for v in arr[i]:
        print ("{} ".format (v), end ="")
    print ("")