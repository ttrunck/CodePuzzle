import itertools
f = open('./input/rosalind_perm.txt', 'r')
n=int(f.readline())

l=list(itertools.permutations(range(1,n+1),n))
print(len(l))
for e in l:
    for i in e:
        print(i, end=' ')
    print()
