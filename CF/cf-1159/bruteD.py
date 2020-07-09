def check (msk, k):
    ok = True
    for sz in range (1, k):
        mp = {}
        for i in range (len(msk)-sz+1):
            if (msk[i:i+sz] in mp):
                mp[msk[i:i+sz]]+=1
            else:
                mp[msk[i:i+sz]] = 1
        for p in mp:
            if (mp[p] == 1):
                ok = False
                break
    if (not ok):
        return None
    mp = {}
    for i in range (len(msk)-k+1):
        # print (msk[i:i+k])
        if (msk[i:i+k] in mp):
            mp[msk[i:i+k]]+=1
        else:
            mp[msk[i:i+k]] = 1
    ok = False
    now = ""
    for p in mp:
        if (mp[p] == 1):
            now = p
            ok = True
            break

    return (msk, now)


n, k = [int (n) for n in input ().split()]

while k > 0 and n >= k:
    ans = []
    for msk in range (2**(n-1), 2**n):
        msk = bin (msk)[2:]
        ret = check (msk, k)
        if (ret != None):
            ans.append (ret)
    print (n, k)
    
    for msk in ans:
        print (msk)
    k -= 2
    # n -= 2