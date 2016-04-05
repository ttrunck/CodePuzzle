#!/usr/local/bin/python3
import os
import re
import sys
import shutil

def find_file(args):
    '''
    Find the good input file, if it is given in command line use this one, else search in downloads and move it in input dir
    '''
    if len(args)==1:
        filename='rosalind_'+args[0][2:-3].lower()+'.txt'
        path_filename=os.path.abspath(os.path.join('input', filename))
        download='/Users/ttrunck/Downloads'
        path_download=os.path.abspath(os.path.join(download,filename))
        if os.path.exists(path_download):
            os.rename(path_download, path_filename)
    else:
        path_filename=os.path.abspath(args[1])
    if not os.path.exists(path_filename):
        raise NameError('Pas de fichier')
    return path_filename


def fasta(file):
    '''
    Given a fasta file, read it and return a dict mapping key to DNA string
    '''
    d={}
    key=''
    s=''
    for line in file:
        if line[0]=='>':
            if key:
                d[key]=s
            key=line.strip()[1:]
            s=''
        else:
            s+=line.strip()
    if key:
        d[key]=s
    return d

def fasta_list(file):
    '''
    Given a fasta file, read it and return a list of DNA string
    '''
    l=[]
    key=''
    s=''
    for line in file:
        if line[0]=='>':
            if key:
                l.append(s)
            key=line.strip()[1:]
            s=''
        else:
            s+=line.strip()
    if key:
        l.append(s)
    return l

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

def prot_mass():
    '''
    Return a dict containg the mass of protein
    '''
    return {'A':   71.03711,'C':   103.00919,'D':   115.02694,'E':   129.04259,'F':   147.06841,'G':   57.02146,'H':   137.05891,'I':   113.08406,'K':   128.09496,'L':   113.08406,'M':   131.04049,'N':   114.04293,'P':   97.05276,'Q':   128.05858,'R':   156.10111,'S':   87.03203,'T':   101.04768,'V':   99.06841,'W':   186.07931,'Y':   163.06333
}

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

def dna_reverse_complement(s):
    '''
    Given a DNA string return its reversed complement
    '''
    s=s.replace('A','t')
    s=s.replace('T','a')
    s=s.replace('C','g')
    s=s.replace('G','c')
    res=''
    for i in reversed(s.upper()):
        res+=i
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

def transition_transversion(s1,s2):
    '''
    return the number of transition and the number of transversion bewteen two DNA string
    '''
    assert len(s1)==len(s2),'Dude your string have not the same length'
    si,ver=0,0
    for i in range(len(s1)):
        if s1[i]!=s2[i]:
            if s1[i]=='A':
                if s2[i]!='G':
                    si+=1
                else:
                    ver+=1
            if s1[i]=='G':
                if s2[i]!='A':
                    si+=1
                else:
                    ver+=1
            if s1[i]=='C':
                if s2[i]!='T':
                    si+=1
                else:
                    ver+=1
            if s1[i]=='T':
                if s2[i]!='C':
                    si+=1
                else:
                    ver+=1
    return si,ver

def hamming(s1,s2):
    '''
    Return the hamming distance between s1 and s2
    '''
    assert len(s1)==len(s2), 'Dude they have not the same size'
    res=0
    for i in range(len(s1)):
        if s1[i]!=s2[i]:
            res+=1
    return res

def complete_spectrum(s):
    mass=prot_mass()
    res=[]
    curr=0.
    for i in range(0,len(s)):
        curr+=mass[s[i]]
        res.append(curr)
    curr=0.
    for i in range(1,len(s)+1):
        curr+=mass[s[-i]]
        res.append(curr)
    return res
    
