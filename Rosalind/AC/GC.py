f = open('./input/rosalind_gc.txt', 'r')

d={}
first=True

for line in f:
    if line[0]=='>':
        if not(first):
            d[s]=t
        first=False
        s=line[1:-1]
        t=''
    else:
        t+=line.strip()
d[s]=t

maxi=0.

def comp(s):
    return (s.count('C')+s.count('G'))/float(len(s))

for k in d:
    if comp(d[k])>maxi:
        maxi=comp(d[k])
        res=k

print('%s\n%f%%' % (res, maxi*100))

