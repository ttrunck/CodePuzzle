#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def fact(n):
    res=1
    for i in range(1,n+1):
        res*=i
    return res

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        n,m=(int(i) for i in file.read().split())
    mod=1000000
    a=fact(n)
    b=fact(n-m)
    c=fact(m)
    res=a//b//c
    for k in range(m+1,n+1):
        b=b//(n-k+1)
        c=c*k
        res=(res+a//b//c)%mod
    print(res)
    

if __name__ == '__main__':
    main()
