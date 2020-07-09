n = input ()

coelho = 0
rato = 0
sapo = 0
for i in range (0, n):
    line = raw_input ()
    line = line.split (' ')
    numb = float(line[0])
    specie = line[1]
    if (specie == 'C'):
        coelho+=numb
    elif (specie == 'R'):
        rato+=numb
    elif (specie == 'S'):
        sapo+=numb
total = float (coelho + rato + sapo)
print "Total: " + str(int(total)) + " cobaias"
print "Total de coelhos: " + str (int(coelho))
print "Total de ratos: " + str (int(rato))
print "Total de sapos: " + str (int(sapo))
print "Percentual de coelhos: " + "%.2lf" % round (coelho*100/total, 2) + " %"
print "Percentual de ratos: " + "%.2lf" % round (rato*100/total, 2) + " %"
print "Percentual de sapos: " + "%.2lf" % round (sapo*100/total, 2) + " %"
