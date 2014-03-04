#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def print_set(s):
    l=[str(i) for i in (list(s))]
    print('{'+', '.join(l)+'}')
    
def read_set(s):
    return set([int(i) for i in s.replace(',','')[1:-1].split()])

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        inp=file.read().split('\n')
        n=int(inp[0])
        a=read_set(inp[1])
        b=read_set(inp[2])
    tot=set(range(1,n+1))
    print_set(a.union(b))
    print_set(a.intersection(b))
    print_set(a.difference(b))
    print_set(b.difference(a))
    print_set(tot.difference(a))
    print_set(tot.difference(b))

if __name__ == '__main__':
    main()
