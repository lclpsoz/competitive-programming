def conv(s):
    cnt = 1
    cur = s[0]
    ans = ""
    for i in range(1, len(s)):
        if (s[i] != cur):
            ans += cur
            ans += hex(cnt)[2:]
            cur = s[i]
            cnt = 1
        else:
            cnt += 1
    ans += cur
    ans += hex(cnt)[2:]
    return ans

print(conv("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzetxxxxxxx"))