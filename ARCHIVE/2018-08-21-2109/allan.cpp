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

	       
