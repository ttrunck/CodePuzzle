#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def compute(n, k, d):
    if n==1 or n==2:
        return 1
    elif (n,k) in d:
        return d[(n,k)]
    else:
        d[(n,k)] = compute(n-1, k, d)+k*compute(n-2, k, d)
        return d[(n,k)]

def main():
    args = sys.argv
    filename = rosalind.find_file(args)
    with open(filename,'r') as file:
        x,y = (int(i) for i in file.read().split())
        d = {}
        print(compute(x,y,d))

if __name__ == '__main__':
    main()
