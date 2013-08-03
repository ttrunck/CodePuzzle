#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import SeqIO

def main(filename):
    res = 0
    with open(filename) as handle:
        q, p = handle.readline().split()
        q, p = int(q), int(p)
        for record in SeqIO.parse(handle, 'fastq'):
            l = sorted(record.letter_annotations["phred_quality"])
            #print l
            #print l[-len(l)*p/100]
            if l[-len(l)*p/100]>=q:
                res += 1
    print res
        
   

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
