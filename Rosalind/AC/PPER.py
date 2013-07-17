#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)

        
def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        n,k=[int(i) for i in file.read().split()]
    print((fact(n)//fact(n-k))%1000000)

if __name__ == '__main__':
    main()
