#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def calc(n,s,x):
    p=1
    for c in s:
        if c=='A' or c=='T':
            p*=(1-x)/2
        else:
            p*=x/2
    return p*(n-len(s)+1)

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        n=int(file.readline())
        s=file.readline().strip()
        a=[float(i) for i in file.read().split()]
    print(' '.join([str(round(calc(n,s,x),5)) for x in a]))

if __name__ == '__main__':
    main()
