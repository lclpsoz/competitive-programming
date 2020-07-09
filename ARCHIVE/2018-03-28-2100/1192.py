n = input ()
for i in range (0, n):
    a = raw_input ()
    if (a[0] == a[2]):
        print (int(a[0])*int(a[2]))
    elif (ord(a[1]) >= ord('A') and ord(a[1]) <= ord('Z')):
        print str(int(a[2])-int(a[0]))
    else:
        print str(int(a[2])+int(a[0]))

