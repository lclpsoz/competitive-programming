inp = raw_input ()
inp = inp.split (' ')
while (int(inp[0]) > 0 and int(inp[1]) > 0):
    print int(inp[0])*int(inp[1])
    while (True):
        try:
            inp = raw_input ()
            inp = inp.split (' ')
            int(inp[0])
        except ValueError:
            continue
        break
