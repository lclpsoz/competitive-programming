from random import randint

n = randint (2, 200)
print (n)
mn = -10000
mx = 10000
st = set()
while (len (st) < n):
    st.add ((randint (mn, mx), randint (mn, mx)))

for p in st:
    print (p[0], p[1])