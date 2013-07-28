#!/usr/bin/env python
#coding: utf-8

import sys

from Bio import ExPASy
from Bio import SwissProt

def main(filename):
    with open(filename) as fin:
        my_seq = fin.read().strip()
    handle = ExPASy.get_sprot_raw(my_seq) 
    record = SwissProt.read(handle)
    for s in [f[2].split(':')[1] for f in record.cross_references if f[0]=='GO' and f[2][0]=='P']:
        print s

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
