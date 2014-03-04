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
        N,x=file.readline().split()
        N=int(N)
        x=float(x)
        s=file.read().strip()
    p=1.
    for c in s:
        if c=='A' or c=='T':
            p*=(1-x)/2
        else:
            p*=x/2
    print(1-(1-p)**N)

if __name__ == '__main__':
    main()
