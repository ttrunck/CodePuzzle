def fact(n):
    if n<= 1:
        return 1
    else:
        return n*fact(n-1)

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    print fact(n)
