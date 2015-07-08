import itertools

def binomial(n, k):
	if k<0 or n<0 or n<k:
		return 0
	if k>n-k:
		return binomial(n, n-k)
	res = 1
	for i in range(k):
		res = res*(n-i)//(i+1)
	return res


tot = 0
for color in range(2,8):
	for val in itertools.product(range(1,11), repeat=color):
		if sum(val) == 20:
			tmp = 1
			for i in val:
				tmp *= binomial(10, i)
			tot += tmp * color * binomial(7, color)


print(tot/binomial(70,20), binomial(70,20))