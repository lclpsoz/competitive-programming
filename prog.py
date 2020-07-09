a = 17
b = 86
qnt = b-a+1
p = 389
q = 995

pp = (p*(a-1))%q
print ("p =", p)
for i in range (qnt):
    pp = (pp+p)%q
    print (a+i, pp, abs (pp-995//2))