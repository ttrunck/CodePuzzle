#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def find(c, l):
    for suivant, char in l:
        if c==char:
            return suivant
    return -1

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        datas=file.read().split()
    t=[[]]
    n=0
    for data in datas:
       curr=0
       for c in data:
           suivant=find(c, t[curr])
           if suivant!=-1:
               curr=suivant
           else:
               n+=1
               t[curr].append((n,c))
               t.append([])
               curr=n
    for i in range(len(t)):
        for elt in t[i]:
            print(i+1, elt[0]+1, elt[1])
        

if __name__ == '__main__':
    main()
