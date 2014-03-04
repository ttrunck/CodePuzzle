#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import urllib.request
import io

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        for name in file:
            name=name.strip()
            url='http://www.uniprot.org/uniprot/'+name+'.fasta'
            s_fasta=urllib.request.urlopen(url).read().decode('utf8')
            s=list(rosalind.fasta(io.StringIO(s_fasta)).values())[0]
            if re.search(r'N[^P][ST][^P]',s):
                print(name)
                for i in range(len(s)-3):
                    if re.search(r'^N[^P][ST][^P]',s[i:i+4]):
                        print(i+1, end= ' ')
                print()

if __name__ == '__main__':
    main()
