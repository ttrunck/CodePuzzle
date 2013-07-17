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
        data=file.read().split()
    d={}
    for read in data:
        if read in d:
            d[read]+=1
            d[rosalind.dna_reverse_complement(read)]+=1
        else:
            d[read]=1
            d[rosalind.dna_reverse_complement(read)]=1
    for read in data:
        if d[read]==1:
            for corr in d.keys():
                if d[corr]>1 and rosalind.hamming(read, corr)==1:
                    print(read+'->'+corr)

if __name__ == '__main__':
    main()
