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
    n=len(s)
    m=len(t)
    tab=[[0 for i in range(m+1)] for j in range(n+1)]
    for i in range(n+1):
        tab[i][0]=i
    for j in range(m+1):
        tab[0][j]=j
    for i in range(1,n+1):
        for j in range(1,m+1):
            tab[i][j]=min(tab[i-1][j]+1, tab[i][j-1]+1)
            if  s[i-1]==t[j-1]:
                tab[i][j]=min(tab[i][j], tab[i-1][j-1]+1)

                #print(tab[n][m])
    res=''
    i,j=n,m
    while i>0 and j>0:
        if s[i-1]==t[j-1] and tab[i][j]==tab[i-1][j-1]+1:
            i-=1
            j-=1
            res=s[i]+res
        elif tab[i][j]==tab[i-1][j]+1:
            i-=1
            res=s[i]+res
        else:
            j-=1
            res=t[j]+res
            
            #print(tab)
    if i==0:
       res=t[:j]+res
    if j==0:
        res=s[:i]+res
    print(res)

if __name__ == '__main__':
    main()
