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

def build(t):
    res=[{t:''}]
    for nb_set in range(5):
        newset={}
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
                        newset[rev]=res[-1][t]+','+(str(j+1) if j!=10 else '01') + ' ' +str(i+1)
        res.append(newset)
    return res

def reverse_string(s):
    res=''
    for c in reversed(s):
        res+=c
    return res

def dist(start,fin,myset):
    q=deque([(start,'')])
    d={start:''} 
    while q:
        s,di=q.popleft()
        for i in range(len(myset)):
            if s in myset[i]:
                return di+','+reverse_string(myset[i][s])
        tmp_hamming_st=rosalind.hamming(s,fin)
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                rev=reverse(s,i,j)
                if (not rev in d) and hamming_bound(rev,tmp_hamming_st):
                    d[s]=di
                    q.append((rev,di+','+str(i+1)+ ' ' + str(j+1)))
    return ''

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        datas=[tuple([int(i) for i in d.split()]) for d in file.read().split('\n') if d!='']    

    s=datas[0]
    t=datas[1]
    myset=build(t)
    sol=dist(s,t,myset)
    # print(sol)
    print(len(sol[1:-1].split(',')))
    for c in sol[1:-1].split(','):
        print(c)

if __name__ == '__main__':
    main()

    
 
