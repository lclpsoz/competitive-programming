lst = []
for n0 in range(0, 10):
    for n1 in range(0, 10):
        for n2 in range(0, 10):
            lst.append([n0, n1, n2])

for x in lst:
    ori = x.copy()
    st = input()
    for i in range(1, len(st)):
        if (st[i-1]+st[i]) == '00':
            x[0] -= 1
        elif(st[i-1]+st[i]) == '01' or (st[i-1]+st[i]) == '10':
            x[1] -= 1
        else:
            x[2] -= 1
    for i in x:
        if i != 0:
            print('-------------------')
            print(st)
            print('WRONG', x)
            print(ori)
            print('-------------------')
            break