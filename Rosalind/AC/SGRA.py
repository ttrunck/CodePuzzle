#!/usr/local/bin/python3
import re
import os
import sys
import shutil
import rosalind

def app(x, l):
    for i in l:
        if abs(x-i)<0.01:
            return True
    return False

def calc(x,mass,dist,datas):
    if x in dist:
        return dist[x]
    res=0
    for i in mass:
        if app(x+i,datas):
            res=max(res, 1+calc(x+i,mass,dist,datas))
    dist[x]=res
    return res

def main():
    args=sys.argv
    filename=rosalind.find_file(args)
    with open(filename,'r') as file:
        datas=sorted([float(i) for i in file.read().split()])
    dist={}
    tmp=rosalind.prot_mass()
    mass={tmp[i]:i for i in tmp}
    maxi=max([calc(i,mass,dist,datas) for i in datas])

    start=datas[0]
    for i in datas:
        if dist[i]==maxi:
            start=i
    while maxi:
        for i in mass:
            if app(start+i, datas) and maxi==dist[start+i]+1:
                maxi-=1
                print(mass[i], end='')
                start=start+i
    print()

if __name__ == '__main__':
    main()
