#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import itertools

def calc(l1, l2):
    diff=[round(i-j,7) for i,j in itertools.product(l1,l2)]
    d={}
    for elt in diff:
        if elt in d:
            d[elt]+=1
        else:
            d[elt]=1
    maxi=-1
    for elt in d:
        if d[elt]>maxi:
            maxi=d[elt]
    return maxi



def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    l=[]
    with open(filename,'r') as file:
        n=int(file.readline())
        for i in range(n):
            l.append(file.readline().strip())
        r=[float(i) for i in file.read().split()]
    mass=rosalind.prot_mass()
    maxi=-1
    res=-1
    for elt in l:
        tmp=calc(r, rosalind.complete_spectrum(elt))
        if  tmp>=maxi:
            maxi=tmp
            res=elt
    print(maxi)
    print(res)
    

if __name__ == '__main__':
    main()
