c = 1
while True:
	s = input()
	if s == "*":
		break
	elif s == "Hajj":
		print("Case %d: Hajj-e-Akbar"%c)
	else:
		print("Case %d: Hajj-e-Asghar"%c)
	c += 1
