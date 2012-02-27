r = [ [-10.0, -10.0, -10.0, -10.0, -10.0, -10.0], [-10.0, -0.04, -0.04, -0.04, 1.0, -10.0],  [-10.0, -0.04, -10.0, -0.04, -1.0, -10.0], [-10.0, -0.04, -0.04, -0.04, -0.04, -10.0], [-10.0, -10.0, -10.0, -10.0, -10.0, -10.0] ]
p = [ [0.8, 0.0 , 0.1, 0.1], [0.0, 0.8, 0.1, 0.1], [0.1, 0.1, 0.8, 0.0], [0.1, 0.1, 0.0, 0.8] ]
K = [0.0, 0.0, 0.0, 0.0]
zaz = []
u = umas1 = r
v = 0
repetir = True
s = len(r)
s1 = len(r[1])
while repetir:
	for i in range(1,s-1):
		for j in range(1,s1-2):
			for k in range(0,len(p)):
				for m in range(0,len(p)):
					a = [ u[i-1][j], u[i+1][j], u[i][j+1], u[i][j-1] ];
					if a[m] == -10:
						a[m] = u[i][j]
					v = v + p[k][m] * a[m]
				K[k] = v
				v = 0
			if u[i][j] == 1 or u[i][j] == -1 or u[i][j] == -10:
				u[i][j] = r[i][j]
			else:
				u[i][j] = r[i][j] + max(K)
	for i in range(1,s-1):
		for j in range(1,s1-1):
			zaz.append(umas1[i][j] - u[i][j])
	for i in range(len(zaz)):
		zaz[i] = abs(zaz[i])
	for i in range(len(zaz)):
		if abs(zaz[i]) < 0.0001:
			repetir = False
	if repetir != False:
		umas1 = u

u2 = u[1:4]

for i in range(0,len(u2)):
		print u2[i][1], u2[i][2], u2[i][3], u2[i][4]

