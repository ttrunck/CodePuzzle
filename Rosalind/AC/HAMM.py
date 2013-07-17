f = open('./input/rosalind_hamm.txt', 'r')
s=f.readline()
t=f.readline()

#res=0
#for i in range(len(s)):
#    if(s[i]!=t[i]):
#        res+=1
#print(res)

print(sum([a != b for a, b in zip(s, t)]))
