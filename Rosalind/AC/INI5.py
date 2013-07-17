fin = open('in', 'r')
fout = open('out', 'w')
compt=0
for line in fin:
    if compt%2==1:
        fout.write(line)
    compt+=1
fout.write('\n')
fout.close()
fin.close()
