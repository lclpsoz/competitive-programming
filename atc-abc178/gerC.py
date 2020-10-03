n = 4
a = [0 for x in range(n)]
def check(arr):
    return 0 in arr and 9 in arr

ans = 0
while 1:
    
    p = 0
    if check(a):
        print(a)
    ans += check(a)
    a[0]+=1
    while a[p] == 10:
        if p == len(a)-1:
            break
        a[p+1]+=1
        a[p] = 0
        p += 1
    if a[p] == 10:
        break
print(ans)