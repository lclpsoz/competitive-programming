n = input ()

mini = 100000000000
pos = 0
ans = 0
a = raw_input ()
a = a.split (' ')
#print a
for i in a:
    try:
        i = int (float(i))
    except ValueError:
        pass
    if (i < mini):
        mini = i
        ans = pos
    pos += 1
print "Menor valor: " + str(mini)
print "Posicao: " + str(ans)
