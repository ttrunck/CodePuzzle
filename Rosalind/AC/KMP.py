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
        s=file.read().strip()
    n=len(s)
    t=[0]*n
    k=0
    for q in range(1,n):
        while k>0 and s[k]!=s[q]:
            k=t[k-1]
        if s[k]==s[q]:
            k+=1
        t[q]=k

    print(' '.join([str(i) for i in t]))

if __name__ == '__main__':
    main()
