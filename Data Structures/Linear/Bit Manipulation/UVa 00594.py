def twosComp(no):
	res = 0
	for i in range(0,32):
		if no%2 == 0:
			res += 2**i
		no //= 2
	return res+1

def convert(no):
	if no < 0:
		no *=-1
		no = twosComp(no)
	b = '{:032b}'.format(no)
	rev = int(b[24:]+b[16:24]+b[8:16]+b[:8],2)
	if rev >  2147483647:
		rev = twosComp(rev) * -1
	return rev

while True:
	try:
		no = int(input())
		print(no,"converts to",convert(no))
	except:
		break
