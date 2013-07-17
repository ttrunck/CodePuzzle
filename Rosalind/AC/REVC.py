f = open('./input/rosalind_revc.txt', 'r')
s=f.read().strip()
s=s.replace('A','t')
s=s.replace('T','a')
s=s.replace('C','g')
s=s.replace('G','c')

for i in reversed(s.upper())<:
    print(i,end='')
print()
