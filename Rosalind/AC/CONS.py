#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind


def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        datas=file.read().split()

    a=[0]*len(datas[0])
    c=a[:]
    g=a[:]
    t=a[:]
    d={'A':a, 'C':c,'G':g, 'T':t}

    for data in datas:
        for i in range(len(data)):
            d[data[i]][i]+=1

    for i in range(len(datas[0])):
        res='A'
        compt=d['A'][i]
        if d['C'][i]>compt:
            res='C'
            compt=d['C'][i]
        if d['G'][i]>compt:
            res='G'
            compt=d['G'][i]
        if d['T'][i]>compt:
            res='T'
            compt=d['T'][i]
        print(res,end='')
    print()

    
    print('A: '+' '.join([str(i) for i in d['A']]))
    print('C: '+' '.join([str(i) for i in d['C']]))
    print('G: '+' '.join([str(i) for i in d['G']]))
    print('T: '+' '.join([str(i) for i in d['T']]))
        

if __name__ == '__main__':
    main()
