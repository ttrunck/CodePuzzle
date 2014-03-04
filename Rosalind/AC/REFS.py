#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import Entrez

def main(filename):
    with open(filename) as fin:
        a,b,c,d = fin.read().strip().split('\n')
        print a,b,c,d
    
    term = '"%s"[Organism] AND "1986/1/1"[PDAT] : "%s"[PDAT] AND "%s"[SLEN] : "%s"[SLEN] AND srcdb_refseq[Properties]' % (a,d,b,c)
    print term
    handle = Entrez.esearch(db="nucleotide", term=term)
    record = Entrez.read(handle)
    print record["Count"]

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
