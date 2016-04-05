#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind
import itertools

from collections import deque

def reverse(t, start, stop):
    s=list(t)
    for i in range(start, (start+stop+1)//2):
        s[stop-i+start],s[i]=s[i],s[stop-i+start]
    return tuple(s)

def hamming_bound(s,bound):
    res=0
    for i in range(len(s)):
        if i+1!=s[i]:
            res+=1
            if res>bound:
                return False
    return True

def translate(s,t):
    d={i:j for (i,j) in zip(t,range(1,11))}
    return tuple([d[i] for i in s])

def build():
    t=tuple(range(1,11))
    res=[{t}]
    for nb_set in range(5):
        newset=set()
        for t in res[-1]:
            for i in range(len(t)):
                for j in range(i+1, len(t)):
                    rev=reverse(t,i,j)
                    to_add=True
                    for k in range(len(res)):
                        if rev in res[k]:
                            to_add=False
                            break
                    if to_add:
                        newset.add(rev)
        res.append(newset)
    return res

def dist(start,fin,myset):
    q=deque([(start,0)])
    d={start:0} 
    while q:
        s,di=q.popleft()
        for i in range(len(myset)):
            if s in myset[i]:
                return di+i
        tmp_hamming_st=rosalind.hamming(s,fin)
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                rev=reverse(s,i,j)
                if (not rev in d) and hamming_bound(rev,tmp_hamming_st):
                    d[s]=di
                    q.append((rev,di+1))
    return -1

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        datas=[tuple([int(i) for i in d.split()]) for d in file.read().split('\n') if d!='']
    myset=build()

    print('Init Done')
    
    nb=0
    while nb<len(datas):
        if nb>0:
            print(' ',end='')
        s=datas[nb]
        t=datas[nb+1]
        s=translate(s,t)
        t=translate(t,t)
        print(dist(s,t,myset), end='')
        nb+=2
    print()

if __name__ == '__main__':
    main()

    
 
