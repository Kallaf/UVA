n = int(input())
names = []
for i in range(n):
	name = input()
	names.append(name)
song = ['Happy','birthday','to','you']
i = 0
while(i<n):
	for j in range(0,16):
		print("%s: " % names[i%n],end='')
		if j == 11:
			print("Rujia")
		else:
			print(song[j%4])
		i += 1
