#!/usr/local/bin/python3.3

f = open('./input/rosalind_lcs.txt', 'r')
words=sorted(f.read().split())

short=words[0]
others=words[1:]

res=''
for i in range(len(short)):
        for j in range(len(short), i+len(res), -1):
            s1 = short[i:j]

            matched_all = True
            for s2 in others:
                if s1 not in s2:
                    matched_all = False
                    break

            if matched_all:
                res=s1
                break
print(res)
