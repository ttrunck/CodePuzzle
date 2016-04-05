#!/usr/local/bin/python

from __future__ import division
import gmpy

num = 0
for i in xrange(569):
    num += gmpy.comb(1000,i)

dem = 2**1000

print num/dem
