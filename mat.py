

def brute (n):
    ret = 0
    for i in range (2, n-1):
        ret += (i-1)*((n-i-1)*(n-i))//2
    return ret
def f (n):
    a = (-1*n**3 + 4*n**2 - 3*n)
    b = (n**4 + 3*n)//2 - n**3 - 2*n**2
    c = ((n-2)**2 * (n-1)**2)//4
    d = -2*n*((2*n**3 - 9*n**2 + 13*n - 6)//6 - 1)
    ret = a + b + c + d
    return ret//2

n = input()
print (f(int(n)))
print (brute(int(n)))
