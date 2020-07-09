arr = raw_input ()
arr = arr.split (' ')

a = int (arr[0])
b = int (arr[1])
c = int (arr[2])

ans = a+b+c

if (ans < 0):
    ans += 24
if (ans >= 24):
    ans -= 24

print ans
