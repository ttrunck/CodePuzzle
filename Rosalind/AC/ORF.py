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
    print('\n'.join(rosalind.RNA_to_ORFs(rosalind.DNA_to_RNA(s))))

if __name__ == '__main__':
    main()
