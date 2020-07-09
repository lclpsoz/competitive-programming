first_line = raw_input ()
while (first_line != 'EOF'):
    first_line_arr = first_line.split(' ')
    n = int(first_line_arr[0])
    r = int(first_line_arr[1])
    surv = raw_input ()
    surv_arr = surv.split(' ')
    not_surv = range(1, n)
    for i in surv_arr:
        print i
