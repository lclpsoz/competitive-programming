x = 7
pos = 1
lst = [0 for x in range(1000001)]
for q in range(50):
    print(x)
    for i in range(1, 1000001):
        if(i%2 == 1 and i%5 > 0 and x%i == 0):
            if(lst[i] == 0):
                lst[i] = pos
    x *= 10
    x += 7
    pos += 1

for i in range(50):
    if(i%2 == 1 and i%5 > 0):
        print(i, lst[i])