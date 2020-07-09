a = raw_input ()
b = a.split (' ')
c = int(b[0])
while (c > 0):
    b[1] = b[1].replace (str(c), '')
    if b[1] == '':
        print 0;
    else:
        print int(b[1])
    a = raw_input ()
    b = a.split (' ')
    c = int(b[0])
