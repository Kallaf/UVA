def getXY(pos):
	x = pos%8
	y = pos//8
	return x,y


def inKingArea(x,y,kx,ky):
	if abs(x-kx)+abs(y-ky) == 1:
		return True
	return False

def afterKing(kx,ky,qx,qy,mx,my):
	if(qy == ky and ky == my and ((qx < kx and kx <= mx) or (mx <= kx and kx < qx))):
		return True
	if(qx == kx and kx == mx and ((qy < ky and ky <= my) or (my <= ky and ky < qy))):
		return True
	return False

def canContiue(king,move):
	return not ((king == 0 and move == 9) or (king == 7 and move == 14) or (king == 56 and move == 49) or (king == 63 and move == 54))

while True:
	try:
		king,queen,move = map(int,input().split())
		kx,ky = getXY(king)
		qx,qy = getXY(queen)
		mx,my = getXY(move)
		if king == queen:
			print("Illegal state")
		elif (queen == move) or (qx != mx and qy != my) or afterKing(kx,ky,qx,qy,mx,my):
			print("Illegal move") 
		elif inKingArea(mx,my,kx,ky):
			print("Move not allowed")
		elif canContiue(king,move):
			print("Continue")
		else:
			print("Stop")
	except EOFError as e:
		break
	
