a = input ()
b = input ()
c = input ()

n1 = 2*b + 4*c
n2 = 2*a + 2*c
n3 = 4*a + 2*b

ans = 100000000
if (n1 < ans):
    ans = n1
if (n2 < ans):
    ans = n2
if (n3 < ans):
    ans = n3
print ans
