from math import sqrt

def crivo(n):
    if (n == 1):
        return []
    if (n == 2):
        return [2]
    if (n == 3):
        return [2, 3]
    sq_n = int(sqrt(n)+1)
    primo = [1 for i in range (0, sq_n)]
    primo[0] = 0
    primo[1] = 0
    n1 = int(sqrt(sq_n)+1)
    for i in range (2, n1+1):
        if primo[i] == 1:
            for j in range (i*i, sq_n, i):
                primo[j] = 0
    inteiros = []
    for i in range (2, sq_n):
        if primo[i] == 1:
            inteiros.append (i)

    return inteiros

def decompor(n):
    primos_ate_n = crivo(n)
    fatores = list(); i = 0
    while n != 1:
        if n%primos_ate_n[i] == 0:
            n = n/primos_ate_n[i]
            fatores.append(primos_ate_n[i])
        else:
            i += 1
        if i == len(primos_ate_n):
            return [n]
    return fatores

def divisores(fatoresn):
    fatores_primos = fatoresn
    divisores = [1]
    for f in fatores_primos:
        divisores += [f*j for j in divisores if f*j not in divisores]
    return divisores

def despojado(n):
    fatores = decompor(n)
    if len(fatores) > 1 and fatores == list(set(fatores)):
        return True
    return False

n = int(input())
div = divisores(decompor(n))
print(div)
count = 0
for i in div:
    if despojado(i):
        count += 1
print(count)
