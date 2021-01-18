t=int(input())

while t>0:
	a = list(map(int,input().split()))
	if(a[0] > a[1]):
		print(">")
	elif(a[0] == a[1]):
		print("=")
	else:
		print("<")
	t = t-1
