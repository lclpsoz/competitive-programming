n = int(input())

while (n > 0):
    x, opt, y, trash, result = input().split(' ')
    x = int(x)
    y = int(y)
    dif = 0
    if (opt == "+"):
        dif += abs ((x+y) - int(result))
    elif (opt == 'x'):
        dif += abs ((x*y) - int(result))
    else:
        dif += abs ((x-y) - int(result))
    print("E", end="")
    for i in range(dif):
        print("r", end="")
    print("ou!")
        
    n -= 1
