f = open('./input/rosalind_revp.txt', 'r')
s=f.read().strip()

def complement(a):
    return a.replace('A','t').replace('T','a').replace('C','g').replace('G','c').upper()

def pal(a):
    b=complement(a)
    for i in range(len(a)):
        if a[i]!=b[-1-i]:
            return False
    return True

for size in range(4,13):
    for i in range(len(s)-size+1):
        if pal(s[i:i+size]):
            print(i+1, size)
