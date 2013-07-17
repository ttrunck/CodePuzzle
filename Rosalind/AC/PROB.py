#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import math

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        s=file.readline().strip()
        t=[float(i) for i in file.readline().split()]
    for p in t:
        res=0.
        for c in s:
            if c=='G' or c=='C':
                res+=math.log10(p/2)
            else:
                res+=math.log10((1-p)/2)
        print(res, end=' ')
    print()

if __name__ == '__main__':
    main()
