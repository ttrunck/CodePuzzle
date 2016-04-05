#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import itertools

def mer4(s):
    d={''.join(tupples):0 for tupples in itertools.product('ACGT',repeat=4)}
    for i in range(len(s)-3):
        assert s[i:i+4] in d, 'Sous chaine inconnue'
        d[s[i:i+4]]+=1
    return [str(i) for key,i in sorted(list(d.items()))]

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        d=rosalind.fasta(file)
    for key in d:
        print(' '.join(mer4(d[key])))
        
if __name__ == '__main__':
    main()
