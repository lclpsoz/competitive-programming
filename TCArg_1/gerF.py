def f(b, m):
    ans = 0
    st = set()
    for i in range(200):
        v = (b*10**i) % m
        if v in st:
            break
        ans += 1
        # print('10**%d %% %d = %d' % (i, m, v))
        st.add(v)
    # print("-----", b, m)
    # print(st)
    return ans

for m in range(2,  101):
    print(m, f(1, m), f(2, m), sep='\t')