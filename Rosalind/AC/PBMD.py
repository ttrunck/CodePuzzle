#!/usr/bin/env python
#coding: utf-8

#ne trie pas par ordre de date de publi.

import sys

from Bio import Entrez

def main(filename):
    with open(filename) as fin:
        name = fin.readline()
        year = fin.readline()
    print name, year
    term = '%s[Author] AND %s [DP])' % (name, year)
    handle = Entrez.esearch(db="pubmed", term=term)
    record = Entrez.read(handle)
    print record["IdList"]

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
