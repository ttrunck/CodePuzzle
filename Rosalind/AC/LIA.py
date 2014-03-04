#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def fact(n):
    return 1 if n==0 else n*fact(n-1)

def binomial(n,k):
    return fact(n)//fact(k)//fact(n-k)

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        k,N=(int(i) for i in file.read().split())
    print(k,N)
    p=0.25
    res=0
    for n in range(N,2**k+1):
        res+=binomial(2**k,n)*p**n*(1-p)**(2**k-n)

    print(res)
    

if __name__ == '__main__':
    main()
