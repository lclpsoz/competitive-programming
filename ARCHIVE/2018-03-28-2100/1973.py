n = int (input ())

aux = list (map(int, input().split()))
total = 0
for i in aux:
    total += i
i = 0
maxi = 0
stolen = 0
while (i >= 0 and i < n and i < len(aux)):
    #print aux
    if (i >= 0 and i < len(aux) and aux[i] > 0):
        aux[i] -= 1
        stolen += 1
        if (aux[i] % 2 == 0):
            i+=1
        else:
            i-=1
    else:
        break
    if (i > maxi):
        maxi = i
if (maxi+1 > n):
    maxi = n-1
print (str(maxi+1) + " " + str(total - stolen))
