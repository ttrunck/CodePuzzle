#!/usr/bin/env python
#coding: utf-8

import sys

from Bio.Seq import translate

def main(filename):
    with open(filename) as fin:
        dna, prot = fin.read().strip().split('\n')
    
    res = 1
    while translate(dna, table=res, stop_symbol='') != prot:
        res += 1
    print res
    

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
