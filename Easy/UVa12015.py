n = int(input())
for index in range(1,n+1):
	links = dict()
	for i in range(10):
		line = input().split()
		link = line[0]
		relevance = int(line[1])
		links[link] = relevance

	m = max(links.values())
	print("Case #%d:" % index)
	for link in links.keys():
		if links[link] == m:
			print(link)
