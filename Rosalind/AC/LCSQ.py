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
        s,t=file.read().split()
    tab=[[0 for i in range(len(t)+1)] for i in range(len(s)+1)]
    for i in range(1,len(s)+1):
        for j in range(1,len(t)+1):
            tab[i][j]=max(tab[i][j-1],
                          tab[i-1][j],
            (1+tab[i-1][j-1]) if s[i-1]==t[j-1] else 0)

    i=len(s)
    j=len(t)
    res=''
    #  print(tab)
    while i>=0 and j>=0:
        if s[i-1]==t[j-1] and tab[i][j]==tab[i-1][j-1]+1:
            res=s[i-1]+res
            i-=1
            j-=1
        elif tab[i][j]==tab[i][j-1]:
            j-=1
        else:
            i-=1
    print(res)
    
            
if __name__ == '__main__':
    main()
