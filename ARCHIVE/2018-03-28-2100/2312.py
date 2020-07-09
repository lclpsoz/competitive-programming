lst = []
n = input ()
for i in range (0, n):
    arr = raw_input ()
    arr = arr.split (' ')
    for i in range (1, 4):
        arr[i] = -1*int (arr[i])
    lst.append (arr)
    sorted_lst = sorted (lst, key=lambda x:(x[1], x[2], x[3], x[0]))

for i in sorted_lst:
    print i[0] + ' ' + str(-1*i[1]) + ' ' + str(-1*i[2]) + ' ' + str(-1*i[3])
