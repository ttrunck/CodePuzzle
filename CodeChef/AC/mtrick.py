T = int(raw_input())
for _ in xrange(T):
    N = int(raw_input())
    res = N*[0]
    t = raw_input().split()
    t = [int(x) for x in t]
    A,B,C = raw_input().split();
    A = int(A)
    B = int(B)
    C = int(C)
    s = raw_input()

    a = 1
    b = 0
    dep = 0
    end = N-1
    lr = True

    for i in xrange(N):
        if s[i]=='A':
            b = (b+A)%C
        elif s[i]=='M':
            a = (a*B)%C
            b = (b*B)%C
        else:
            lr = not lr

        if lr:
            res[i] = (t[dep]*a+b)%C
            dep += 1
        else:
            res[i] = (t[end]*a+b)%C
            end -=1

    print ' '.join([str(x) for x in res])
