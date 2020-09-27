ax = 1
for i in range(2, 10001, 2):
    ax *= i
    y = ax
    qnt = 0
    # print(i, ax)
    while(y%10 == 0):
        y = y//10
        qnt+=1
    print(i, qnt)