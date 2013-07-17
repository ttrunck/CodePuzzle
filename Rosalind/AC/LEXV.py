f = open('./input/rosalind_lexv.txt', 'r')
s=f.readline().strip().split(' ')

n=int(f.readline())

def affiche(taille):
    if taille>0:
        tmp_list=affiche(taille-1)
        res=[]
        for i in s:
            if taille>1:
                res.append(i)
            res.extend([i+elt for elt in tmp_list])
        return res
    else:
        return ['']
    
for i in affiche(n):
    print(i)

