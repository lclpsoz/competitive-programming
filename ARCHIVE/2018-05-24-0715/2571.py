m, p, j, x = input().split(' ')
m = int (m)
x = int (x)
p = float(p)
j = float(j)

l = int(0)
r = int(2)
aux = 1-(p/100)
m *= (j/100)
while (m*(aux**r) >= x):
    r *= r
while (l < r):
    mid = int((l+r)/2)+1
    if (m*(aux**mid) < x):
        r = mid-1
    else:
        l = mid
    #print (str(l) + " " + str(r))
print (l)
