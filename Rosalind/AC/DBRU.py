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
        datas=file.read().split()
    s=set(datas)
    for data in datas:
        s.add(rosalind.dna_reverse_complement(data))
    for elt in sorted(list(s)):
        print('('+elt[:-1]+', '+elt[1:]+')')

if __name__ == '__main__':
    main()
