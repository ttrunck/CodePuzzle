#f = open('./input/rosalind_rna.txt', 'r')
#l=f.read().strip()
#for i in l:
#    if(i=='T'):
#        print('U',end='')
#    else:
#        print(i,end='')
#print()

f = open('./input/rosalind_rna.txt', 'r')
print(f.read().strip().replace('T','U'))
