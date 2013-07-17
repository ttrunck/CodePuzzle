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
        l=rosalind.fasta_list(file)
    res=[[rosalind.hamming(i,j)/len(j) for i in l] for j in l]
    for line in res:
        print(' '.join([str(i) for i in line]))

if __name__ == '__main__':
    main()
