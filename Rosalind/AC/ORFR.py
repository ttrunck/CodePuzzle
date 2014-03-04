#!/usr/bin/env python
#coding: utf-8

import sys

def DNA_to_RNA(s):
    '''
    Convert a string representing a DNA into a string representing a RNA
    '''
    return s.replace('T','U')

def rna_codon():
    '''
    Return a dict containing the translation codon from RNA to PROT
    '''
    return {'UUU':'F','UUC':'F','UUA':'L','UUG':'L','UCU':'S','UCC':'S','UCA':'S','UCG':'S','UAU':'Y','UAC':'Y','UAA':'','UAG':'','UGU':'C','UGC':'C','UGA':'','UGG':'W','CUU':'L','CUC':'L','CUA':'L','CUG':'L','CCU':'P','CCC':'P','CCA':'P','CCG':'P','CAU':'H','CAC':'H','CAA':'Q','CAG':'Q','CGU':'R','CGC':'R','CGA':'R','CGG':'R','AUU':'I','AUC':'I','AUA':'I','AUG':'M','ACU':'T','ACC':'T','ACA':'T','ACG':'T','AAU':'N','AAC':'N','AAA':'K','AAG':'K','AGU':'S','AGC':'S','AGA':'R','AGG':'R','GUU':'V','GUC':'V','GUA':'V','GUG':'V','GCU':'A','GCC':'A','GCA':'A','GCG':'A','GAU':'D','GAC':'D','GAA':'E','GAG':'E','GGU':'G','GGC':'G','GGA':'G','GGG':'G'}

def rna_reverse_complement(s):
    '''
    Given a RNA string return its reversed complement
    '''
    s=s.replace('A','u')
    s=s.replace('U','a')
    s=s.replace('C','g')
    s=s.replace('G','c')
    res=''
    for i in reversed(s.upper()):
        res+=i
    return res

def RNA_to_PROT(s):
    '''
    Convert a string representing a RNA into a string representing a PROT
    '''
    d=rna_codon()
    res=''
    for i in range(0,len(s),3):
        if len(s[i:i+3])==3:
            res+=d[s[i:i+3]]
        else:
            print('Houston we have a problem in RNA_to_PROT')
    return res


def RNA_to_ORFs(s):
    '''
    Convert a string representing a RNA into a list of ORF prots
    '''
    d=rna_codon()
    start='AUG'
    stop=['UAG','UGA','UAA']
    res=set()
    for ss in [s,rna_reverse_complement(s)]:
        for i in range(0,len(ss)):
            if ss[i:i+3]==start:
                j=i
                while j<=len(ss):
                    if ss[j:j+3] in stop:
                        res.add(RNA_to_PROT(ss[i:j]))
                        break
                    j+=3
    return list(res)

def main(filename):
    with open(filename) as fin:
        dna = fin.read().strip()
    
    print max(RNA_to_ORFs(DNA_to_RNA(dna)), key=lambda x:len(x))
    

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
