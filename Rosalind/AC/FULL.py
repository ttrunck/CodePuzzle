#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def egal(x,y):
    return abs(x-y)<0.01

def app(x, l):
    for key in l:
        if egal(x, key):
            return True
    return False

def rem(x,l):
    for key in l:
        if egal(x,key):
            l.remove(key)
    return l

def next(mini, maxi, l, d):
    for key in d:
        if app(mini+key,l) and app(maxi-key,l):
            print(d[key], end='')
            l=rem(mini,l)
            l=rem(maxi,l)
            return mini+key,maxi-key , l

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        l=[round(float(i),3) for i in file.read().split()]
        l=l[1:]
    gauche=min(l)
    droite=max(l)
    tmp=rosalind.prot_mass()
    d={round(tmp[i],3):i for i in tmp}

    while len(l)>2:
        (gauche, droite, l) = next(gauche, droite, l, d)
    print()
        

if __name__ == '__main__':
    main()
