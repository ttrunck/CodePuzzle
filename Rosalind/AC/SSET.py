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
        n=int(file.read())
    print((2**n)%1000000)

if __name__ == '__main__':
    main()
