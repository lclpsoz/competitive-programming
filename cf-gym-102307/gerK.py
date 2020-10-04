fib = [1, 1]

for i in range(2, 100001):
    fib.append(fib[i-2]+fib[i-1])
print(fib[-1])

