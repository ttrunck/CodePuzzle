f = open('./input/rosalind_iev.txt', 'r')
t=[int(i) for i in (f.readline().strip().split(' '))]

print(
    t[0]*2+
    t[1]*2+
    t[2]*2+
    t[3]*1.5+
    t[4]
    )
