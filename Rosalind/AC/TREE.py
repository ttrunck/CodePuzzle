f = open('./input/rosalind_tree.txt', 'r')
n=int(f.readline())
s=f.read().strip().split('\n')
print(n-len(s)-1)
