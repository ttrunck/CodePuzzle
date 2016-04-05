#!/usr/bin/env python
#coding: utf-8

import sys

def main(filename):
    with open(filename) as fin:
        n = int(fin.readline())
        t = fin.readline().split()

    t = map(int, t)
    inc = [(0,[])]*(n+1)
    for i in t:
        x,y = max(inc[:i])
        inc[i] = (x+1,y+[i])
    print(" ".join(map(str,max(inc)[1])))
    
    t = [n-i+1 for i in t]
    inc = [(0,[])]*(n+1)
    for i in t:
        x,y = max(inc[:i])
        inc[i] = (x+1,y+[i])
    print(" ".join(map(str,[n-i+1 for i in max(inc)[1]])))
    


if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
