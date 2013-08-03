#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import SeqIO

def main(filename):
    with open(filename) as fin:
        records = SeqIO.parse(fin, 'fastq')
        count = SeqIO.write(records, 'out', 'fasta')

   

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
