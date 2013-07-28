#!/usr/bin/env python
#coding: utf-8

import sys

from Bio.Seq import Seq

def main(filename):
    with open(filename) as fin:
        my_seq = fin.read()
    print my_seq.count('A'), my_seq.count('C'), my_seq.count('G'), my_seq.count('T')

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
