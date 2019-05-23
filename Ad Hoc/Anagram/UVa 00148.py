dictionary = []
dictCount = []
while True:
	word = input()
	if word == "#":
		break
	dictionary.append(word)
	count = [0] * 27
	for c in word:
		count[ord(c)-ord('A')] += 1
	dictCount.append(count)

can = [False] * len(dictionary)

def setCan(count,index):
	global dictCount,sentence,dictionary,can
	for i in range(0,26):
		if count[i] < dictCount[index][i]:
			can[index] = False
			return
	can[index] = True


sentence = ""
inStmt = [False] * len(dictionary)
def ans(count,index,words):
	global dictCount,sentence,inStmt,dictionary,can
	flag = True
	newCount = [0] * 27
	for i in range(0,26):
		if count[i] < dictCount[index][i]:
			return
		if count[i] > dictCount[index][i]:
			flag = False
		newCount[i] = count[i]-dictCount[index][i];
	
	words.append(dictionary[index])
	if flag:
		print(sentence,"=",end="")
		for word in words:
			print(" %s" % word,end="")
		print()
		del words[-1]
		return

	for i in range(index+1,len(dictionary)):
		if (not inStmt[i]) and can[i]:
			ans(newCount,i,words)

	del words[-1]

while True:
	sentence = input()
	if sentence == "#":
		break
	count = [0] * 27
	for c in sentence:
		if c != ' ':
			count[ord(c)-ord('A')] += 1

	splited = sentence.split()
	
	for i in range(0,len(dictionary)):
		inStmt[i] = dictionary[i] in splited
		setCan(count,i)
	for i in range(0,len(dictionary)):
		if (not inStmt[i]) and can[i]:
			ans(count,i,[])
