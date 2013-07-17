f = open('./input/rosalind_dna.txt', 'r')
l=f.read().strip()
freq = {'A': 0, 'C': 0, 'G': 0, 'T': 0}
for i in l:
    freq[i] = freq[i] + 1

print(freq['A'], freq['C'], freq['G'], freq['T'])
