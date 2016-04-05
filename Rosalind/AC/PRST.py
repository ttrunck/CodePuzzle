#!/usr/bin/env python
#coding: utf-8

#ne trie pas par ordre de date de publi.

import sys

from Bio.ExPASy import ScanProsite

def main(filename):
    with open(filename) as fin:
        seq = fin.readline()
    handle = ScanProsite.scan(seq=seq)
    result = ScanProsite.read(handle)
    result = [(r['start'], r['signature_ac']) for r in result]
    result = sorted(result, key=lambda x:x[0])
    print result[-1][1]

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
