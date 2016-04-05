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
    print records[0].seq
    print '------------------------'
    print records[1].seq

#now use http://www.ebi.ac.uk/Tools/psa/emboss_stretcher/nucleotide.html

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
