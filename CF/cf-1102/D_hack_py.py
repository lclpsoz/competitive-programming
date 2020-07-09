n=int(input())
s=input()

c1=0
c2=0
c3=0

for i in range (n):
	if(s[i]=='0'):
		c1+=1
	elif(s[i]=='1'):
		c2+=1
	elif(s[i]=='2'):
		c3+=1

st=[]
for i in range (n):
	st.append(s[i])
if(c1==c2==c3):
	print(s)


elif(c1==(n//3) and (c2<c3)):

	for i in range (n):
		if(st[i]=='2' and c2<c3):
			st[i]=1
			c2+=1
			c3-=1
		

	for i in range (n):
		print(st[i],end="")
	print()

elif(c1==n//3) and (c3<c2):
	for i in range (n-1,-1,-1):
		if(st[i]=='1' and c3<c2):
			st[i]=2
			c3+=1
			c2-=1
	for i in range (n):
		print(st[i],end="")
	print()

elif(c2==(n//3) and (c1<c3)):

	for i in range (n):
		if(st[i]=='2' and c1<c3):
			st[i]=0
			c1+=1
			c3-=1
		

	for i in range (n):
		print(st[i],end="")
	print()

elif(c2==n//3) and (c3<c1):
	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c3<c1):
			st[i]=2
			c3+=1
			c1-=1
		
	for i in range (n):
		print(st[i],end="")
	print()

elif(c3==(n//3) and (c1<c2)):

	for i in range (n):
		if(st[i]=='1' and c1<c2):
			st[i]=0
			c1+=1
			c2-=1
		

	for i in range (n):
		print(st[i],end="")
	print()

elif(c3==n//3) and (c2<c1):
	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c2<c1):
			st[i]=1
			c2+=1
			c1-=1
		
	for i in range (n):
		print(st[i],end="")
	print()

elif(c3>(n//3) and (c2<(n//3)) and (c1<(n//3))):
	for i in range (n):
		if(st[i]=='2' and c1<n//3):
			st[i]=0
			c1+=1
			c3-=1

	for i in range (n):
		if(st[i]=='2' and c2<n//3):
			st[i]=1
			c2+=1
			c3-=1

	for i in range (n):
		print(st[i],end="")
	print()

elif(c2>(n//3) and (c3<(n//3)) and (c1<(n//3))):
	for i in range (n):
		if(st[i]=='1' and c1<n//3):
			st[i]=0
			c1+=1
			c2-=1

	for i in range (n-1,-1,-1):
		if(st[i]=='1' and c3<n//3):
			st[i]=2
			c3+=1
			c2-=1

	for i in range (n):
		print(st[i],end="")
	print()

elif(c1>(n//3) and (c2<(n//3)) and (c3<(n//3))):
	
	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c3<n//3):
			st[i]=2
			c3+=1
			c1-=1

	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c2<n//3):
			st[i]=1
			c2+=1
			c1-=1


	for i in range (n):
		print(st[i],end="")
	print()

elif(c3>n//3 and c2>n//3 and c1<n//3):
	for i in range (n):
		if(st[i]=='2' and c3>n//3):
			st[i]=0
			c1+=1
			c3-=1

		elif(st[i]=='1' and c2>n//3):
			st[i]=0
			c1+=1
			c2-=1

	for i in range (n):
		print(st[i],end="")
	print()

elif(c1>n//3 and c2>n//3 and c3<n//3):
	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c1>n//3):
			st[i]=2
			c1-=1
			c3+=1
		elif(st[i]=='1' and c2>n//3):
			st[i]=2
			c2-=1
			c3+=1
	for i in range (n):
		print(st[i],end="")
	print()

elif(c1>n//3 and c3>n//3 and c2<n//3):
	for i in range (n):
		if(st[i]=='2' and c3>n//3):
			st[i]=1
			c3-=1
			c2+=1

	for i in range (n-1,-1,-1):
		if(st[i]=='0' and c1>n//3):
			st[i]=1
			c1-=1
			c2+=1

	for i in range (n):
		print(st[i],end="")
	print()
