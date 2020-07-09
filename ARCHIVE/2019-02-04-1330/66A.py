n = int (input())

ans = ""
if (n <= 127):
    ans = "byte"
elif (n <= 32767):
    ans = "short"
elif (n <= 2147483647):
    ans = "int"
elif (n <= 9223372036854775807):
    ans = "long"
else:
    ans = "BigInteger"

print (ans)
