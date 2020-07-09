b = int(input())
e = int(input())

while (b > 10):
    lim = b
    b = 0
    while (lim):
        b += lim%10
        lim = int(lim/10)
#print (b)

if (e == 0):
    print(1)
elif (b == 0):
    print(0)
elif (b == 1):
    print(1)
elif (b == 2):
    ans = [2, 4, 8, 7, 5, 1]
    print(ans[((e+5)%6)])
elif (b == 3):
    if (e == 1):
        print(1)
    else:
        print(9)
elif (b == 4):
    ans = [4, 7, 1]
    print(ans[((e+2)%3)])
elif (b == 5):
    ans = [5, 7, 8, 4, 2, 1]
    print(ans[((e+5)%6)])
elif (b == 6):
    if (e == 1):
        print(6)
    else:
        print(9)
elif (b == 7):
    ans = [7, 4, 1]
    print(ans[(e+2)%3])
elif (b == 8):
    ans = [8, 1]
    print(ans[(e+1)%2])
elif (b == 9):
    print(9)
