import itertools
f = open('./input/rosalind_sign.txt', 'r')
n=int(f.readline())

l=list(itertools.permutations(range(1,n+1),n))
print(len(l)*2**n)
for e in l:
    for k in range(2**n):
        kk=k
        for i in e:
            if kk%2==0:
                print(-i, end=' ')
            else:
                print(i, end=' ')
            kk//=2
            
        print()
