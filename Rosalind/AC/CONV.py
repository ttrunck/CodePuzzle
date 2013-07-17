#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import itertools


def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        s1=[float(i) for i in file.readline().split()]
        s2=[float(i) for i in file.readline().split()]
    diff=[round(i-j,7) for i,j in itertools.product(s1,s2)]
    d={}
    for elt in diff:
        if elt in d:
            d[elt]+=1
        else:
            d[elt]=1
    maxi=-1
    res=-1
    for elt in d:
        if d[elt]>maxi:
            res=elt
            maxi=d[elt]
    print(maxi)
    print(res)

if __name__ == '__main__':
    main()
