ap, x, y, x2, y2 = map(int, input().split (' '))

d = (abs(x-x2)**2+abs(y-y2)**2)**0.5

if (d == 0):
    r = ap/2
    x3 = x
    y3 = (y+y+ap)/2
elif (d >= ap):
    r = ap
    x3 = x
    y3 = y
else:
    r = (ap+d)/2

    vx = x - x2;
    vy = y - y2;
    vx /= d;
    vy /= d;
    vx *= r;
    vy *= r;

    x3 = vx + x2;
    y3 = vy + y2;

print(x3, y3, r)
