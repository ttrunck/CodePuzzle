#!/usr/bin/python

import urllib
import re
import sys

def main():
    args=sys.argv
    if len(args)!= 2:
        n=100
    else:
        n=int(args[1])
    try:
        ufile = urllib.urlopen('http://rosalind.info/statistics/top/')
        data=ufile.read()
    except IOError:
        print 'problem reading url:', 'http://rosalind.info/statistics/top/'
    l= re.findall(r'<a href="/statistics/countries/\w+/" title="([^\"]+)"', data)[:n]
    d={i:l.count(i) for i in l}
    print sorted(d.items(), key=(lambda (x,y):y), reverse=True)

if __name__ == '__main__':
    main()
