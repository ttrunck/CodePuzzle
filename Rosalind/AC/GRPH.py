f = open('./input/rosalind_grph.txt', 'r')

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

for a in d:
    for b in d:
        if a!=b:
            if d[a][:3]==d[b][-3:]:
                print(b, a)
