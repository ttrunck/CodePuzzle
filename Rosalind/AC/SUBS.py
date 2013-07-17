f = open('./input/rosalind_subs.txt', 'r')
s=f.readline().strip()
t=f.readline().strip()

#res=0
#for i in range(len(s)):
#    if(s[i]!=t[i]):
#        res+=1
#print(res)

for i in range(len(s)-len(t)):
    res=True
    for j in range(len(t)):
        if s[i+j]!=t[j]:
            res=False
    if res:
        print(i+1, end=' ')
print()
