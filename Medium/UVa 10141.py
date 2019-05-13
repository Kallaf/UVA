c = 1
while True:
	max_r = 0
	min_d = 0
	n,p = map(int,input().split())
	if n==0 and p==0:
		break
	for i in range(n):
		input()
	for i in range(p):
		company = input()
		d,r = input().split()
		d = float(d)
		r = int(r)
		if r > max_r or (r == max_r and d < min_d):
			max_r = r
			min_d = d
			winner = company
		for j in range(r):
			input()
	if c > 1:
		print()
	print("RFP #%d" % c)
	print(winner)
	c += 1
