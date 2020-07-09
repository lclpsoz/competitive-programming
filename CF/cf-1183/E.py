n, k = input().split (' ')
n = int (n)
k = int (k)
s = input()
s = "-" + s
dp = [ [ 0 for i in range (110)] for j in range (110)]
added = [ [ 0 for i in range (110)] for j in range (110)]
lst = [0 for i in range (310)]
lstAdded = [0 for i in range (310)]
for i in range (0, 110):
    dp[0][i] = 1
vec = list()
st = set()
for i in range (1, n+1):
    st.add (s[i])
    dp[1][i] = len (st)
vec.append (1)
vec.append (dp[1][n])
for t in range (2, n+1):
    for i in range(310):
        lst[i] = 0
        lstAdded[i] = 0
    for i in range (1, n+1):
        dp[t][i] = dp[t-1][i-1] + dp[t][i-1] - lstAdded[ord(s[i])]
        #if (lst[ord(s[i])] > 0):
        #     dp[t][i] += dp[t-1][lst[ord(s[i])]-1]
        lstAdded[ord(s[i])] += dp[t][i] - dp[t][i-1]
        added[t][i] = dp[t][i] - dp[t][i-1]
        lst[ord(s[i])] = i
    vec.append (dp[t][n])
    # print (t, dp[t][n])

ans = 0
qnt = 0
while (k > 0 and len (vec)):
    now = vec.pop()
    #print (now, k, ans)
    use = min (k, now)
    k = k - use
    ans += qnt * use
    qnt+=1
if (k == 0):
    print (ans)
else:
    print (-1)