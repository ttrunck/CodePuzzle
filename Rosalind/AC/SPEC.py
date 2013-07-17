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
        datas=[float(i) for i in file.read().split()]
    d=rosalind.prot_mass()

    
    inv_d={round(d[k],4):k for k in d}
    #print(inv_d)
    for i in range(len(datas)-1):
        if round(datas[i+1]-datas[i],4) in inv_d:
            print(inv_d[round(datas[i+1]-datas[i],4)],end='')
        elif round(datas[i+1]-datas[i],4)+0.0001 in inv_d:
            print(inv_d[round(datas[i+1]-datas[i],4)+0.001],end='')
        elif round(datas[i+1]-datas[i],4)-0.0001 in inv_d:
            print(inv_d[round(datas[i+1]-datas[i],4)-0.001],end='')
        else:
            print('PROBLEM!!!',round(datas[i+1]-datas[i],4))
    print()

if __name__ == '__main__':
    main()
