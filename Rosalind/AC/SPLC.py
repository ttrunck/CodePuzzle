#!/usr/local/bin/python3
import re
import os
import sys
import rosalind

def main():
    filename=os.path.abspath(os.path.join('input', 'rosalind_'+sys.argv[0][2:-3].lower()+'.txt'))
    with open(filename,'r') as file:
        ss=file.read().split()
        s=ss[0]
        introns=ss[1:]
        for intron in introns:
            s=s.replace(intron,'')
        print(rosalind.RNA_to_PROT(rosalind.DNA_to_RNA(s)))

if __name__ == '__main__':
    main()
