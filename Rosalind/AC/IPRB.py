f = open('./input/rosalind_iprb.txt', 'r')
s=f.readline().split();
k=float(s[0])
m=float(s[1])
n=float(s[2])
nn=k+m+n
print(k/nn+(m/nn)*0.5+(m/nn)*0.5*(k/(nn-1)+(m-1)/(nn-1)*0.5)+n/nn*(k/(nn-1)+m/(nn-1)*0.5))
