mod = 10**9 + 7

st = set()
base = 10
val = 7
i = 0
while val not in st:
    if(i%100000 == 0):
        print(i, val)
    i+=1
    st.add(val)
    val = (val+base*7)%mod
    base = (base*10)%mod