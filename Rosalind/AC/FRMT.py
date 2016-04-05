#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import Entrez
from Bio import SeqIO

def main(filename):
    with open(filename) as fin:
        seq = fin.readline()
    handle = Entrez.efetch(db="nucleotide", id=[seq], rettype="fasta")
    records = list (SeqIO.parse(handle, "fasta"))
    res = min(records, key=lambda x:len(x.seq))
    print '>'+res.description
    print res.seq

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
