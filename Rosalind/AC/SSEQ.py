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
        s=file.readline().strip()
        t=file.readline().strip()
    curr=0
    for c in t:
        n=s.find(c)+1
        s=s[n:]
        curr+=n
        print(curr, end=' ')
    print()

if __name__ == '__main__':
    main()
