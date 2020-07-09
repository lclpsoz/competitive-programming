def crivo(n):
    from math import sqrt, ceil
    primos_ate_n = [False, False]+[True for i in range(2, int(ceil(sqrt(n))+2))]
    for i in range(len(primos_ate_n)):
        if primos_ate_n[i]:
            try:
                for j in range(i*i, len(primos_ate_n), i):
                    primos_ate_n[j] = False
            except IndexError:
                break
    primos_ate_n = [i for i in range(len(primos_ate_n)) if primos_ate_n[i]]
    return primos_ate_n

def decompor(n, crivo):
    primos_ate_n = [i for i in crivo if i <= n]
    fatores = list(); i = 0
    while n != 1:
        if n%primos_ate_n[i] == 0:
            n = int(n/primos_ate_n[i])
            fatores.append(primos_ate_n[i])
        else:
            i += 1
        if i == len(primos_ate_n):
            fatores.append(n)
            return fatores
    return fatores

def divisores(fatoresn):
    fatores_primos = fatoresn
    divisores = [1]
    for f in fatores_primos:
        divisores += [f*j for j in divisores if f*j not in divisores]
    return divisores

def despojado(n, crivo):
    fatores = decompor(n, crivo)
    if len(fatores) < 2:
        return False
    for i in fatores:
        if fatores.count(i) > 1:
            return False
        return True


print(decompor(26, crivo(26)))
