from datetime import datetime

raw_string = raw_input()
hr_1, min_1, hr_2, min_2 = raw_string.split()
hr_1 = int(hr_1)
hr_2 = int(hr_2)
min_1 = int(min_1)
min_2 = int(min_2)
while ((hr_1 + hr_2 + min_1 + min_2) > 0):
    time_1 = datetime(2000, 1, 1, hr_1, min_1)
    time_2 = datetime(2000, 1, 1, hr_2, min_2)
    delta = time_2 - time_1
    delta = int(delta.total_seconds())
    if (delta < 0):
        delta += 3600*24
    print (delta/60)

    raw_string = raw_input()
    hr_1, min_1, hr_2, min_2 = raw_string.split()
    hr_1 = int(hr_1)
    hr_2 = int(hr_2)
    min_1 = int(min_1)
    min_2 = int(min_2)
