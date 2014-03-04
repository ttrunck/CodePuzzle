#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import SeqIO


def main(filename):
    res = 0
    with open(filename) as fin:
        for record in SeqIO.parse(fin, "fasta") :
            if str(record.seq) == str(record.seq.reverse_complement()):
                res += 1
    print res
    

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
