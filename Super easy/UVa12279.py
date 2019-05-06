c = 1
while True:
	n = int(input())
	if n == 0:
		break
	zeros = 0
	non_zeros = 0
	x = map(int,input().split())
	for i in x:
		if i != 0:
			non_zeros += 1
		else:
			zeros += 1
	print("Case %d: %d"%(c,non_zeros-zeros))
	c += 1
