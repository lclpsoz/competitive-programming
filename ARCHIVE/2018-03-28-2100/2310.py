n = input()
a = 0
b = 0
c = 0
a1 = 0
b1 = 0
c1 = 0
for i in range (0, n):
    name = raw_input ()
    f = raw_input ()
    f = f.split (' ')
    s = raw_input ()
    s = s.split (' ')

    a += float (f[0])
    b += float (f[1])
    c += float (f[2])

    a1 += float (s[0])
    b1 += float (s[1])
    c1 += float (s[2])

print "Pontos de Saque: %0.2lf %%." % (a1*100/a)
print "Pontos de Bloqueio: %0.2lf %%." % (b1*100/b)
print "Pontos de Ataque: %0.2lf %%." % (c1*100/c)
