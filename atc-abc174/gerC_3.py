base = 10
now = 9
for i in range(1000):
    now  = 10**i
    print(len(str(now)), end=' = ')
    ax = now
    div = 2
    while ax > 1:
        if ax%div == 0:
            print(div, end=', ')
        while ax%div == 0:
            ax /= div
        div += 1
    now += base
    base *= 10
    print('')