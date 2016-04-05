#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def find_ok(s, ens):
    for t in ens:
        for n in range(len(s),len(s)//2,-1):
            #print(s[-n:], t[:n])
            if s[-n:]==t[:n]:
                #print(t,t[n:])
                return t,t[n:]
    return ('','')

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        l=file.read().split()
    for s in l:
        curr=s
        curr_set=set(l)
        n=0
        res=s
        while curr and curr_set:
            curr_set.remove(curr)
            n+=1
            curr,extend=find_ok(curr,curr_set)
            res+=extend
        if(n==len(l)):
            print(res)
    

if __name__ == '__main__':
    main()
