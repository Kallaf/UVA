def x(s,i):
	if(s == "1"):
		return i+1

	return x(str(len(s)),i+1)

while True:
	s = input()
	if s=="END":
		break
	print(x(s,0))
