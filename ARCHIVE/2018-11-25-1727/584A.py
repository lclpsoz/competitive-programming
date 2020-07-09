arr = input()
n, t = arr.split(' ')
n = int (n)
t = int (t)

if (n == 1 and t == 10):
    print ("-1")
else:
    num = 1

    for i in range (n-1):
        num*=10

    while (num%t != 0):
        num+=1

    print (num)
