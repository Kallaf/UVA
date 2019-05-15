Dict = dict({'+x': dict({'No': '+x','+y': '+y', '-y': '-y','+z': '+z', '-z':'-z' }) ,
	'-x': dict({'No': '-x','+y': '-y', '-y': '+y','+z': '-z', '-z':'+z' }),
	'+y': dict({'No': '+y','+y': '-x', '-y': '+x','+z': '+y', '-z':'+y' }),
	'-y': dict({'No': '-y','+y': '+x', '-y': '-x','+z': '-y', '-z':'-y' }),
	'+z': dict({'No': '+z','+y': '+z', '-y': '+z','+z': '-x', '-z':'+x' }),
	'-z': dict({'No': '-z','+y': '-z', '-y': '-z','+z': '+x', '-z':'-x' })})

while True:
	n = int(input())
	if n == 0:
		break
	ans = '+x'
	arr = input().split()
	for a in arr:
		ans = Dict[ans][a]
	print(ans)
