#!/usr/bin/env python
#coding: utf-8

import sys

def main(filename):
    with open(filename) as fin:
        words = {}
        for word in fin.read().split():
            if not word in words:
                words[word] = 1
            else:
                words[word] = words[word]+1
        for key in words:
            print key, words[key]

if __name__ == '__main__':
    if(len(sys.argv)==1):
        print 'Il faut un fichier d\'entrée'
    else:
        main(sys.argv[-1])
