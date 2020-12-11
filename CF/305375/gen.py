import random, string

def conv(s, j):
    cnt = 1
    cur = s[0]
    ans = ""
    for i in range(1, len(s)):
        if (s[i] != cur or j == i):
            ans += cur
            ans += hex(cnt)[2:].upper()
            cur = s[i]
            cnt = 1
        else:
            cnt += 1
    ans += cur
    ans += hex(cnt)[2:].upper()
    return ans

def conv_t(s):
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

fin = open("in", "w")
fout = open("out", "w")

N = 100
for _ in range(100):
    rand_word = ""
    i = 0
    while i < N:
        rand_int = random.randint(97, 122)
        fac = random.randint(1, N - i)
        rand_word += fac * chr(rand_int)
        i += fac
    fin.write(rand_word + "\n")
    
    best = conv_t(rand_word)
    for i in range(len(rand_word)):
        copy = conv(rand_word[0:i] + rand_word[i + 1:len(rand_word)], i)
        if len(copy) < len(best):
            best = copy
            continue;
        if copy < best:
            best = copy
    fout.write(best + "\n")

