#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import Entrez

def main(filename):
    with open(filename) as fin:
        inp= fin.read().split()
    print inp
    
    handle = Entrez.esearch(db="nucleotide", term='"'
                            +inp[0] 
                            + '"[organism] AND ("'
                            + inp[1] 
                            + '"[PDAT] : "'
                            + inp[2]
                            + '"[PDAT])')
    record = Entrez.read(handle)
    print record["Count"]

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
