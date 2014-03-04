#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind


def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        d=rosalind.fasta(file)
    s1,s2=list(d.values())
    si,ver=rosalind.transition_transversion(s1,s2)
    print(si,ver)
    print(ver/si)

if __name__ == '__main__':
    main()
