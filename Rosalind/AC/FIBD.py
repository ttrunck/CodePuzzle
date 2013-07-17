#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def compute(n, k, d):
    if n<=0:
        return 0,0
    elif n==1:
        return (1,0)
    elif n==2:
        return (0,1)
    elif (n,k) in d:
        return d[(n,k)]
    else:
        (p1, g1)= compute(n-1, k, d)
        (p3, g3)= compute(n-k, k, d)        
        d[(n,k)] = g1, g1+p1-p3
        return d[(n,k)]

def main():
    args = sys.argv
    filename = rosalind.find_file(args)
    with open(filename,'r') as file:
        x,y = (int(i) for i in file.read().split())
        d = {}
        p,g = compute(x,y,d)
        print(p+g)

if __name__ == '__main__':
    main()
