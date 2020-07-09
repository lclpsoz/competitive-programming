arr = raw_input ()
arr = arr.split (' ')

a = int (arr[0])
b = int (arr[1])

if (a == b):
    ans = 24
elif (a > b):
    ans = (24-a)+b
else:
    ans = b-a

print "O JOGO DUROU "+ str (ans) + " HORA(S)"
