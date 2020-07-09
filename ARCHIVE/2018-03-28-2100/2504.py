import time
from datetime import date
import sys

base = date (2016, 11, 7)
for line in sys.stdin:
    arr = line[:-1].split('/', 2)
    #print arr
    for i in range(0,3):
        arr[i] = int(arr[i]);
    now = date (arr[2], arr[1], arr[0])
    dif = int((base - now).days)
    if (dif%23 == 0):
        str1 = "ZERADO"
    elif (dif%23 < 12):
        str1 = "POSITIVO"
    else:
        str1 = "NEGATIVO"
    if (dif%28 == 0 or dif%28 == 14):
        str2 = "ZERADO"
    else:
        str2 = "POSITIVO"
    if (dif%33 == 0):
        str3 = "ZERADO"
    elif (dif%33 < 17):
        str3 = "POSITIVO"
    else:
        str3 = "NEGATIVO"
    #print str(dif % 23) + " " + str(dif%28) + " " + str(dif%33)
    print str1 + " " + str2 + " " + str3
