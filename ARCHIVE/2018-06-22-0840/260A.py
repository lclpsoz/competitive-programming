arr = input().split(' ')
a = int(arr[0])
b = int(arr[1])
n = int(arr[2])

while (n > 0):
    test = False
    a*=10
    for i in range(11):
        a+=i
        if (a%b == 0):
            test = True
            break
        else:
            a-=i

    if (test == False):
        break
    n-=1

if (n > 0):
    print(-1)
else:
    print(a)
