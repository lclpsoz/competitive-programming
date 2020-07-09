from datetime import date

n = input()
while (n > 0):

    ans = 0
    qnt = 0
    bef_cons = 0;
    bef = date (1700, 1, 1)
    for i in range(0, n):

        the_string = raw_input()
        day, month, year, now_cons = the_string.split()
        day = int(day)
        month = int(month)
        year = int(year)
        now_cons = int(now_cons)
        now = date (year, month, day)

        delta = now - bef;
        if (delta.days == 1):
            ans += now_cons - bef_cons
            qnt += 1;

        bef_cons = now_cons
        bef = now

    print ('{0} {1}'.format(qnt, ans))
    n = input()
