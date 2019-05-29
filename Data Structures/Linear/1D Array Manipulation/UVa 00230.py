books = []
while True:
	line = input()
	if line == "END":
		break
	temp = line.split("by")
	arr = []
	arr.append(temp[1][1:])
	arr.append(temp[0][:-1])
	arr.append(False)
	arr.append(False)
	books.append(arr)

books.sort()

def find(title):
	global books
	for i in range (0,len(books)):
			if title == books[i][1]:
				return i
	return -1

while True:
	line = input()
	if line == "END":
		break
	arr = line.split(" ")
	kind = arr[0]
	title = ""
	if len(arr) > 1:
		title += arr[1]
	for i in range(2,len(arr)):
		title += " "+arr[i]
	if kind == "BORROW":
		i = find(title)
		books[i][2] = True
		books[i][3] = False
	elif kind == "RETURN":
		i = find(title)
		books[i][3] = True
	else:
		before = -1
		for i in range(0,len(books)):
			if not books[i][2]:
				before = i
			elif books[i][3]:
				books[i][2] = False
				books[i][3] = False
				if before == -1:
					print("Put",books[i][1],"first")
				else:
					print("Put",books[i][1],"after",books[before][1])
				before = i
		print("END")
