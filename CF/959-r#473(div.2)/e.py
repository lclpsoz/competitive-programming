n = int(input())

def pow2 (x):
    r = 1
    while (x > 0):
        x-=1
        r*=2
    return r

# Using DP bottom_up technic to
# calculate answer to powers of
# two n
def val_pow_2 (x):
    lst = []
    lst.append(0)
    for i in range(x):
        lst.append(2*lst[i]+pow2(i))
    return lst

# Maximum expoent of power of two
# smaller than x
def lg2 (x):
    r = 0;
    ans = 1;
    while (x > 1):
        x = int(x/2)
        ans *= 2
        r+=1
    return r

# Maximum power of two smaller
# than x
def max_pow_2 (x):
    ans = 1;
    while (x > 1):
        x = int(x/2)
        ans *= 2
    return ans

def func (x, lst):
    if (bin(x).count("1") == 1):
        return lst[lg2(x)]
    elif (x == 0):
        return 0
    else:
        y = max_pow_2 (x)
        return lst[lg2(y)] + y + func (x-y, lst)

lst = val_pow_2 (int(lg2(n)))
#for i in range(len(lst)):
#    if (pow2(i) > 1e12):
#        break
#    print (str(pow2(i)) + ": " + str(lst[i]))

print (func (n, lst))
