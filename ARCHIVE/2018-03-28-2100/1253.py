import sys
a = input()
for i in range(0, a):
    str1 = raw_input()
    a = input()
    for i in str1:
        c = ord(i)-a
        while (c < ord("A")):
            c = ord("A") - c - 1
            c = ord("Z") - c
        sys.stdout.write (chr(c))
    print
