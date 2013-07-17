f = open('./input/rosalind_mrna.txt', 'r')
s=f.readline().strip()

M=1000000

d={
'F':2,
'L':2+4,
'S':4+2,
'Y':2,
'C':2,
'W':1,
'P':4,
'H':2,
'Q':2,
'R':4+2,
'I':3,
'M':1,
'T':4,
'N':2,
'K':2,
'V':4,
'A':4,
'D':2,
'E':2,
'G':4
    }

res=3
for i in s:
    res= (res*d[i])%M
print(res)
